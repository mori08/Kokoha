#include "GameManager.h"
#include "../MyColor.h"
#include "../MyLibrary.h"

// オブジェクト
#include "Object/Player/GamePlayer.h"
#include "Object/Enemy/ChaseEnemy.h"
#include "Object/Enemy/RandomEnemy.h"
#include "Object/Enemy/ImitateEnemy.h"
#include "Object/Enemy/ClingEnemy.h"
#include "Object/Enemy/PatrolTeamEnemy.h"
#include "Object/Light/EnemyLight.h"
#include "Object/Attack/ChaseEnemyAttack.h"
#include "Object/Goal/GameGoal.h"
#include "Object/Goal/RandomGoal.h"
#include "Object/Goal/RunAwayGoal.h"
#include "Object/Goal/ImitateGoal.h"
#include "Object/Goal/LockGoal.h"
#include "Object/Goal/LeaderGoal.h"
#include "Object/Goal/LastGoal.h"
#include "Object/Hole/StraightHole.h"
#include "Object/Hole/RandomHole.h"
#include "Object/Hole/ChaseHole.h"
#include "Object/Hole/RandomBeetleHole.h"
#include "Object/Hole/ShotHole.h"
#include "Object/Hole/SatelliteHole.h"
#include "Object/Hole/ClingBeetleHole.h"
#include "Object/Hole/VirusBeetleHole.h"

// 状態
#include "State/AccessState.h"
#include "State/PlayingState.h"
#include "State/InfoState.h"
#include "State/Tutorial/TutorialInitState.h"

#include "../Cassette/CassetteManager.h"
#include "../Input/InputManager.h"


namespace
{
	// オブジェクトの名前の列
	constexpr size_t OBJECT_NAME_COLUMN = 0;
	// オブジェクトの座標の列
	constexpr size_t OBJECT_POS_COLUMN = 1;
}


Kokoha::GameManager::GameManager()
	: mState(std::make_unique<AccessState>())
{
	// プレイヤー
	setGenerateObjectFunc<GamePlayer>(U"Player");

	// 敵
	setGenerateObjectFunc<BlackEnemy>            (U"StopEnemy");
	setGenerateObjectFunc<ChaseEnemy<BlackEnemy>>(U"ChaseEnemy");
	setGenerateObjectFunc<RandomEnemy>           (U"RandomEnemy");
	setGenerateObjectFunc<ImitateEnemy>          (U"ImitateEnemy");
	setGenerateObjectFunc<ClingEnemy>            (U"ClingEnemy");
	setGenerateObjectFunc<PatrolTeamEnemy>       (U"PatrolTeam");

	// ゴール
	setGenerateObjectFunc<GameGoal>   (U"Goal");
	setGenerateObjectFunc<RandomGoal> (U"RandomGoal");
	setGenerateObjectFunc<RunAwayGoal>(U"RunAwayGoal");
	setGenerateObjectFunc<ImitateGoal>(U"ImitateGoal");
	setGenerateObjectFunc<LockGoal>   (U"LockGoal");
	setGenerateObjectFunc<LeaderGoal> (U"LeaderGoal");
	setGenerateObjectFunc<LastGoal>   (U"LastGoal");

	// 白い敵の穴
	setGenerateObjectFunc<UpHole>          (U"UpHole");
	setGenerateObjectFunc<RightHole>       (U"RightHole");
	setGenerateObjectFunc<DownHole>        (U"DownHole");
	setGenerateObjectFunc<LeftHole>        (U"LeftHole");
	setGenerateObjectFunc<RandomHole>      (U"RandomHole");
	setGenerateObjectFunc<ChaseHole>       (U"ChaseHole");
	setGenerateObjectFunc<RandomBeetleHole>(U"RandomBeetleHole");
	setGenerateObjectFunc<ShotHole>        (U"ShotHole");
	setGenerateObjectFunc<SatelliteHole>   (U"SatelliteHole");
	setGenerateObjectFunc<ClingBeetleHole> (U"ClingBeetleHole");
	setGenerateObjectFunc<VirusBeetleHole> (U"VirusBeetleHole");

	AccessState::setRobotIcon();
	InfoState::setInfoMap();
}


void Kokoha::GameManager::init()
{
	// 状態の初期化
	setState(std::make_unique<AccessState>());

	// ステージの初期化
	mStageData.init();

	// オブジェクトの全削除
	mObjectList.clear();

	// 装備の初期化
	mEquipmentId = 0;
	CassetteManager::instance().getEquipment(mEquipmentId).initEffect();

	// プレイヤーの速さの初期化
	mPlayerSpeed.init();

	// 敵のライトを消す
	GameEnemy::lightOff();
}


Optional<String> Kokoha::GameManager::load()
{
	const FilePath filePath = U"Assets/Data/Game/" + mName + U".csv";

	// 初期化
	init();

	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// CSVファイルの確認
	CSVData csv;
	readCSV(csv, filePath);
	if (!csv)
	{
		errorMessage += U"CSVファイルを読み込めません.\n";
		errorMessage += U"ファイル名 > " + filePath;
		return errorMessage;
	}
	
	errorMessage += U"ファイル名 > " + filePath;
	int32 readingRow = 0;

	// ステージの設定
	if (csv.rows() < StageData::HEIGHT)
	{
		errorMessage += U"csvデータの行数が足りません\n";
		errorMessage += U"行数 > + " + ToString(1 + csv.rows());
		return errorMessage;
	}
	for (readingRow = 0; readingRow < StageData::HEIGHT; ++readingRow)
	{
		if (csv.columns(readingRow) < StageData::WIDTH)
		{
			errorMessage += U"csvデータの列数が足りません\n";
			errorMessage += ToString(readingRow + 1) + U"行目の列数 > + " + ToString(csv.rows());
			return errorMessage;
		}
		for (int32 column = 0; column < StageData::WIDTH; ++column)
		{
			if (csv[readingRow][column] == U"1")
			{
				mStageData.setWall(Point(column, readingRow));
			}
		}
	}

	// 経路探索
	mStageData.searchPath();

	// オブジェクトの生成
	for (; readingRow < csv.rows(); ++readingRow)
	{
		const String& OBJ_NAME = csv[readingRow][OBJECT_NAME_COLUMN];
		if (OBJ_NAME == U"Tutorial")
		{
			mState = std::make_unique<TutorialInitState>();
			return none;
		}

		if (!mGenerateObjectMap.count(OBJ_NAME))
		{
			errorMessage += ToString(readingRow + 1) + U"行目.\n";
			errorMessage += U"登録されていないオブジェクトです.\n";
			errorMessage += U"検出値 > " + OBJ_NAME;
			return errorMessage;
		}

		try
		{
			Vec2 pos = StageData::squareToPixel(Parse<Point>(csv[readingRow][OBJECT_POS_COLUMN]));
			mObjectList.emplace_back(mGenerateObjectMap[OBJ_NAME](pos));
		}
		catch (const ParseError&)
		{
			errorMessage += ToString(readingRow + 1) + U"行目.\n";
			errorMessage += U"座標に変換できません.\n";
			errorMessage += U"検出値 > " + csv[readingRow][OBJECT_POS_COLUMN];
			return errorMessage;
		}
	}
	
	return none;
}


Optional<String> Kokoha::GameManager::reload()
{
	const FilePath filePath = U"Assets/Data/Game/" + mName + U".csv";

	// 状態の初期化
	setState(std::make_unique<AccessState>());

	// オブジェクトの全削除
	mObjectList.clear();

	// 装備の初期化
	mEquipmentId = 0;
	CassetteManager::instance().getEquipment(mEquipmentId).initEffect();

	// プレイヤーの速さの初期化
	mPlayerSpeed.init();

	// 敵のライトを消す
	GameEnemy::lightOff();

	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// CSVファイルの確認
	CSVData csv;
	readCSV(csv, filePath);
	if (!csv)
	{
		errorMessage += U"CSVファイルを読み込めません.\n";
		errorMessage += U"ファイル名 > " + filePath;
		return errorMessage;
	}

	errorMessage += U"ファイル名 > " + filePath;
	int32 readingRow = StageData::HEIGHT;

	// オブジェクトの生成
	for (; readingRow < csv.rows(); ++readingRow)
	{
		const String& OBJ_NAME = csv[readingRow][OBJECT_NAME_COLUMN];
		if (!mGenerateObjectMap.count(OBJ_NAME))
		{
			errorMessage += ToString(readingRow + 1) + U"行目.\n";
			errorMessage += U"登録されていないオブジェクトです.\n";
			errorMessage += U"検出値 > " + OBJ_NAME;
			return errorMessage;
		}

		try
		{
			Vec2 pos = StageData::squareToPixel(Parse<Point>(csv[readingRow][OBJECT_POS_COLUMN]));
			mObjectList.emplace_back(mGenerateObjectMap[OBJ_NAME](pos));
		}
		catch (const ParseError&)
		{
			errorMessage += ToString(readingRow + 1) + U"行目.\n";
			errorMessage += U"座標に変換できません.\n";
			errorMessage += U"検出値 > " + csv[readingRow][OBJECT_POS_COLUMN];
			return errorMessage;
		}
	}

	return none;
}


void Kokoha::GameManager::update()
{
	// 装備の切り替え
	if (InputManager::instance().decision())
	{
		changeEquipment();
	}
	// 装備の更新
	CassetteManager::instance().getEquipment(mEquipmentId).updateEffect();

	updateObject();
}


void Kokoha::GameManager::draw() const
{
#ifdef _DEBUG
	static bool debugMode = true;
	debugMode ^= Key0.up();

	// デバッグ時に薄い明りとマスを示す線を描画
	if (debugMode)
	{
		Scene::Rect().draw(Color(MyWhite, 0x40));
		for (int32 i = 0; i < StageData::N; ++i)
		{
			const Point square = StageData::integerToSquare(i);
			Rect(StageData::SQUARE_SIZE * square, StageData::SQUARE_SIZE).drawFrame(1, MyBlack);
		}
	}
#endif // _DEBUG

	for (const auto& object : mObjectList) { object->drawLight(); }

	for (const auto& object : mObjectList) { object->draw(); }

	mStageData.draw();
}


void Kokoha::GameManager::updateObject()
{
	// プレイヤーの速度の更新
	mPlayerSpeed.update();

	// オブジェクトの追加
	for (auto&& object : mAddObjectList) { mObjectList.emplace_back(std::move(object)); }
	mAddObjectList.clear();

	// オブジェクトの更新
	GameEnemy::lightUpdate();
	for (auto&& object : mObjectList) { object->update(); }

	// 他オブジェクトの確認
	for (auto&& objA = mObjectList.begin(); objA != mObjectList.end(); ++objA)
	{
		auto objB = objA;
		while (++objB != mObjectList.end())
		{
			(*objA)->checkAnother(**objB);
			(*objB)->checkAnother(**objA);
		}
	}

	// オブジェクトの削除
	Erase_if(mObjectList, [](const GameObjectPtr& obj) {return obj->isEraseAble(); });
}


void Kokoha::GameManager::changeEquipment()
{
	++mEquipmentId;

	mPlayerSpeed.init();

	GameEnemy::lightOff();

	CassetteManager::instance().getEquipment(mEquipmentId).initEffect();
}
