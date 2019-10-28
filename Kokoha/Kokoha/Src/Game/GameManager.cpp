#include "GameManager.h"
#include "../MyColor.h"

// オブジェクト
#include "Object/Player/GamePlayer.h"
#include "Object/Enemy/ChaseEnemy.h"


namespace
{
	// オブジェクトの名前の列
	constexpr size_t OBJECT_NAME_COLUMN = 0;
	// オブジェクトの座標の列
	constexpr size_t OBJECT_POS_COLUMN = 1;
}


Kokoha::GameManager::GameManager()
{
	setGenerateObjectFunc<GamePlayer>(U"Player");
	setGenerateObjectFunc<ChaseEnemy<BlackEnemy>>(U"BlackChase");
	setGenerateObjectFunc<ChaseEnemy<WhiteEnemy>>(U"WhiteChase");
}


void Kokoha::GameManager::init()
{
	mStageData.init();
}


Optional<String> Kokoha::GameManager::load(const String& stageName)
{
	const FilePath filePath = U"Assets/Data/Game/" + stageName + U".csv";

	// 初期化
	init();

	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// CSVファイルの確認
	CSVData csv(filePath);
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
	// オブジェクトの更新
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


void Kokoha::GameManager::draw() const
{
#ifdef _DEBUG
	static bool debugMode = false;
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
