#include "AdventureManager.h"
#include "../MyColor.h"
#include "../Input/InputManager.h"
#include "Window/MenuWindow.h"
#include "../Record/RecordManager.h"


namespace
{
	// 部屋の幅の行数
	constexpr size_t ROOM_WIDTH_ROW = 0;

	// プレイヤーについての行数
	constexpr size_t PLAYER_ROW = 1;
	// プレイヤーの座標についての列数
	constexpr size_t PLAYER_POS_COLUMN = 0;
	// プレイヤーの方向についての列数
	constexpr size_t PLAYER_DIRECTION_COLUMN = 1;

	// オブジェクトの情報の行数
	constexpr size_t OBJECT_ROW = 2;
	// オブジェクトの座標の列数
	constexpr size_t POS_COLUMN = 0;
	// オブジェクトの画像名の列数
	constexpr size_t TEXTURE_NAME_COLUMN = 1;
	// オブジェクトの通過可能フラグの列数
	constexpr size_t IS_PASSING_COLUMN = 2;
	// 開くウィンドウ名の列数
	constexpr size_t WINDOW_NAME_COLUMN = 3;

	// 描画範囲
	constexpr Rect SIZE(0, 0, 640, 420);

	// ステージファイル名
	const Array<String> AREA_FILE_NAME
	{
		U"StoreRoom",
		U"StoreRoom",
		U"StoreRoom",
		U"DoctorRoom",
		U"StoreRoom",
		U"StoreRoom",
		U"StoreRoom"
	};
}


Kokoha::AdventureManager::AdventureManager()
	: mCameraPos(0,0)
	, mAreaId(0)
{
	AdventureObject::registerWindow();
}


Optional<String> Kokoha::AdventureManager::load()
{
	// シーン遷移先の初期化
	mSceneName = none;

	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// フィールド情報の初期化
	mObjectList.clear();

	// ステージ番号をファイル名に変換
	String fileName = AREA_FILE_NAME[Max(0, Min(mAreaId, (int32)AREA_FILE_NAME.size() - 1))];
	fileName = U"Assets/Data/Adventure/" + fileName + U".csv";
	RecordManager::instance().setRecord(U"AreaId", mAreaId);

	// CSVファイルの確認
	CSVData csv(fileName);
	if (csv.isEmpty())
	{
		errorMessage += U"CSVファイルを読み込めません.\n";
		errorMessage += U"ファイル名 > " + fileName;
		return errorMessage;
	}

	// 部屋の幅の範囲
	try
	{
		mRoomWidth = Parse<int32>(csv[ROOM_WIDTH_ROW][0]);
	}
	catch (const ParseError&)
	{
		errorMessage += U"整数値に変換できません.\n";
		errorMessage += U"部屋の幅 > " + csv[ROOM_WIDTH_ROW][0] + U"\n";
		errorMessage += fileName + U" : " + ToString(ROOM_WIDTH_ROW + 1) + U"行目";
		return errorMessage;
	}

	// プレイヤーの初期位置
	try
	{
		mPlayer.set
		(
			Parse<int32>(csv[PLAYER_ROW][PLAYER_POS_COLUMN]),
			Parse<int32>(csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN])
		);
		changeCameraPos();
	}
	catch (const ParseError&)
	{
		errorMessage += U"整数値に変換できません.\n";
		errorMessage += U"座標 > " + csv[PLAYER_ROW][PLAYER_POS_COLUMN] + U"\n";
		errorMessage += U"方向 > " + csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN] + U"\n";
		errorMessage += fileName + U" : " + ToString(PLAYER_ROW + 1) + U"行目";
		return errorMessage;
	}

	// 左右に壁となるオブジェクトの設置
	mObjectList.emplace_back
	(
		Point(-10, 0),
		U"Invisible",
		false
	);
	mObjectList.emplace_back
	(
		Point(mRoomWidth, 0),
		U"Invisible",
		false
	);

	// オブジェクトの整理
	for (size_t row = OBJECT_ROW; row < csv.rows(); ++row)
	{
		try
		{
			mObjectList.emplace_back
			(
				Parse<Point>(csv[row][POS_COLUMN]),
				csv[row][TEXTURE_NAME_COLUMN],
				Parse<bool>(csv[row][IS_PASSING_COLUMN])
			);
		}
		catch(const ParseError&)
		{
			errorMessage += U"オブジェクトを生成できません.\n";
			errorMessage += fileName + U" : " + ToString(row + 1) + U"行目";
			return errorMessage;
		}
	}

	// ウィンドウを全て閉じる
	mWindowList.clear();

	return none;
}


void Kokoha::AdventureManager::setPlayerFromRecord()
{
	mPlayer.set
	(
		RecordManager::instance().getRecord(U"PlayerPos"),
		(RecordManager::instance().getRecord(U"PlayerDirection") == 1) ? (+1) : (-1)
	);

	changeCameraPos();
}


void Kokoha::AdventureManager::update()
{
	// ウィンドウを開いているとき その更新
	if (!mWindowList.empty())
	{
		for (auto&& window : mWindowList) { window->update(); }
		mWindowList.back()->selectedUpdate();
		return;
	}

	// キャンセルボタンでメニューを開く
	if (InputManager::instance().cancel())
	{
		openWindow(std::make_unique<MenuWindow>());
		return;
	}

	// オブジェクトの更新
	mPlayer.update(mObjectList);
	changeCameraPos();
	for (auto& object : mObjectList)
	{
		object.update(mPlayer.getRegion());
	}
}


void Kokoha::AdventureManager::draw() const
{
	SIZE.draw(MyWhite);

	mPlayer.draw(mCameraPos);

	for (const auto& object : mObjectList)
	{
		object.draw(mCameraPos);
	}

	for (const auto& window : mWindowList)
	{
		window->draw();
	}
}


void Kokoha::AdventureManager::closeWindow()
{
	if (mWindowList.empty()) { return; }
	mWindowList.pop_back();
	
	if (!mWindowList.empty())
	{
		mWindowList.back()->select();
	}
}


void Kokoha::AdventureManager::clearWindow()
{
	mWindowList.clear();
}


void Kokoha::AdventureManager::changeCameraPos()
{
	int32 x = mPlayer.getRegion().center().asPoint().x - Scene::Center().x;

	if (mRoomWidth < Scene::Width())
	{
		mCameraPos.x = x;
		return;
	}

	mCameraPos.x = Max(0, Min(x, mRoomWidth - Scene::Width()));
}
