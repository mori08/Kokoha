#include "PossessCassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../AdventureManager.h"
#include "../../../MyColor.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Cassette/CassetteManager.h"


namespace
{
	// 描画の基準点
	constexpr Point DRAW_POINT(400, 60);

	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(60, 60);

	// ボタンの名前
	const String BUTTON_NAME(U"Possess");

	// アイコンの列数
	constexpr int32 ICON_COLUMN = 3;
}


void Kokoha::PossessCassetteView::setButton()const
{
	for (int32 i = 0; i < CassetteManager::instance().getCassetteList().size(); ++i)
	{
		Point buttonPoint
			= DRAW_POINT + BUTTON_SIZE * Point(i % ICON_COLUMN, i / ICON_COLUMN);

		// ボタンの設定
		ButtonManager::instance().registerButton
		(
			BUTTON_NAME + ToString(i),
			Rect(buttonPoint, BUTTON_SIZE)
		);

		// ボタンの縦の位置関係の設定
		if (i >= ICON_COLUMN)
		{
			ButtonManager::instance().setVerticalAdjacentButton
			(
				BUTTON_NAME + ToString(i - ICON_COLUMN),
				BUTTON_NAME + ToString(i)
			);
		}

		// ボタンの横の位置関係の設定
		if (i % ICON_COLUMN != 0)
		{
			ButtonManager::instance().setHorizontalAdjacentButton
			(
				BUTTON_NAME + ToString(i - 1),
				BUTTON_NAME + ToString(i)
			);
		}
	}
}


void Kokoha::PossessCassetteView::update()
{
	
}


void Kokoha::PossessCassetteView::draw() const
{
	for (int32 i = 0; i < CassetteManager::instance().getCassetteList().size(); ++i)
	{
		Point drawIconPoint 
			= DRAW_POINT + BUTTON_SIZE * Point(i % ICON_COLUMN, i / ICON_COLUMN);

		if (CassetteManager::instance().getCassetteList()[i]->getState() == Cassette::NO_POSSESS_STATE)
		{
			continue;
		}

		CassetteManager::instance().getCassetteList()[i]->getIconTexture().draw(drawIconPoint);
	}
}

