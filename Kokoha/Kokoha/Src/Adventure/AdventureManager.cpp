#include "AdventureManager.h"


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

	// 床を除く描画範囲のサイズ
	constexpr Size ADVENTURE_SIZE(640, 420);
}


Kokoha::AdventureManager::AdventureManager()
{
	
}


Optional<String> Kokoha::AdventureManager::load(const String& fileName)
{
	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// フィールド情報の初期化
	mObjectList.clear();

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

	// プレイヤーの範囲
	try
	{
		mPlayer.set
		(
			Parse<int32>(csv[PLAYER_ROW][PLAYER_POS_COLUMN]),
			Parse<int32>(csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN])
		);
	}
	catch (const ParseError&)
	{
		errorMessage += U"整数値に変換できません.\n";
		errorMessage += U"座標 > " + csv[PLAYER_ROW][PLAYER_POS_COLUMN] + U"\n";
		errorMessage += U"方向 > " + csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN] + U"\n";
		errorMessage += fileName + U" : " + ToString(PLAYER_ROW + 1) + U"行目";
		return errorMessage;
	}

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
		catch(const ParseError& e)
		{
			errorMessage += U"オブジェクトを生成できません.\n";
			errorMessage += fileName + U" : " + ToString(row + 1) + U"行目";
			return errorMessage;
		}
	}

	return none;
}


void Kokoha::AdventureManager::update()
{
	mPlayer.update(mObjectList);

	for (auto& object : mObjectList)
	{
		object.update(mPlayer.getRegion());
	}
}


void Kokoha::AdventureManager::draw() const
{
	mPlayer.draw(mCameraPos);

	for (const auto& object : mObjectList)
	{
		object.draw(mCameraPos);
	}
}
