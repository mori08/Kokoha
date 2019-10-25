#include "GameManager.h"
#include "../MyColor.h"


void Kokoha::GameManager::init()
{
	mStageData.init();
}


Optional<String> Kokoha::GameManager::load(const String& fileName)
{
	// 初期化
	init();

	// エラーメッセージ
	String errorMessage = U"[AdventureManager::load]\n";

	// CSVファイルの確認
	CSVData csv(fileName);
	if (csv.isEmpty())
	{
		errorMessage += U"CSVファイルを読み込めません.\n";
		errorMessage += U"ファイル名 > " + fileName;
		return errorMessage;
	}
	
	int32 readingRow = 0;

	// ステージの設定
	if (csv.rows() < StageData::HEIGHT)
	{
		errorMessage += U"csvデータの行数が足りません";
		errorMessage += U"行数 > + " + ToString(1 + csv.rows());
		return errorMessage;
	}
	for (readingRow = 0; readingRow < StageData::HEIGHT; ++readingRow)
	{
		if (csv.columns(readingRow) < StageData::WIDTH)
		{
			errorMessage += U"csvデータの列数が足りません";
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
	
	return none;
}


void Kokoha::GameManager::update()
{

}


void Kokoha::GameManager::draw() const
{
	Scene::Rect().draw(MyWhite);
	mStageData.draw();
}
