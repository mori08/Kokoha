#include "CheckStageScene.h"

#include "../GameManager.h"
#include "../../MyColor.h"

#include "../../MyLibrary.h"

Kokoha::CheckStageScene::CheckStageScene(const InitData& init)
	: IScene(init)
{
	GameManager::instance().load(U"Test");
}

void Kokoha::CheckStageScene::update()
{
}

void Kokoha::CheckStageScene::draw() const
{
	Scene::Rect().draw(MyWhite);

	for (int32 i : GameManager::instance().getStageData().getCornerGraphEdgeList(Cursor::PosF()))
	{
		Line(Cursor::PosF(), StageData::integerToPixel(i)).draw(Palette::Black);
		Circle(StageData::integerToPixel(i), 10).draw(Palette::Red);
	}

	for (int32 i : Range(0, StageData::N - 1))
	{
		const Point square = StageData::integerToSquare(i);
		Rect(StageData::SQUARE_SIZE * square, StageData::SQUARE_SIZE).drawFrame(1, MyBlack);

		if (GameManager::instance().getStageData().isTouchingCorner(square))
		{
			Rect(StageData::SQUARE_SIZE * square, StageData::SQUARE_SIZE).draw(Color(0xFF, 0, 0, 0x80));
		}

		if (GameManager::instance().getStageData().isWalkAble(square)) { continue; }

		Rect(StageData::SQUARE_SIZE * square, StageData::SQUARE_SIZE).draw(MyBlack);
	}
}
