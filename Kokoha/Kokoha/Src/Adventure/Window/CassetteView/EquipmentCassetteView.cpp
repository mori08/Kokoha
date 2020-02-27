#include "EquipmentCassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../../MyColor.h"
#include "../../../Cassette/CassetteManager.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Adventure/AdventureManager.h"
#include "../../../Record/RecordManager.h"


namespace
{
	// ボタンの描画位置の基準となる点
	constexpr std::array<Point, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_POINT
	{
		Point(120,150),
		Point(120,270)
	};

	// ボタンの名前
	const std::array<String, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_NAME
	{
		U"EquipmentA",
		U"EquipmentB"
	};

	// ボタンの数
	constexpr int32 BUTTON_NUM = 3;

	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(60, 60);

	// 装備ＡのＩＤ
	constexpr size_t ID_A = 0;
	// 装備ＢのＩＤ
	constexpr size_t ID_B = 1;

	// ウィンドウを表示する座標の補正
	constexpr Point WINDOW_OFFSET(60, -20);

	// コスト表示の座標
	constexpr Point COST_POS(100, -35);
}


void Kokoha::EquipmentCassetteView::setButton() const
{
	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		for (int32 equipId = 0; equipId < CassetteManager::EQUIPMENT_NUM; ++equipId)
		{
			Point buttonPoint
				= BUTTON_POINT[equipId] + BUTTON_SIZE * Point(i, 0);

			// ボタンの設定
			ButtonManager::instance().registerButton
			(
				BUTTON_NAME[equipId] + ToString(i),
				Rect(buttonPoint, BUTTON_SIZE)
			);

			// ボタンを押したときの処理の設定
			ButtonManager::instance().setOnClickFunc
			(
				BUTTON_NAME[equipId] + ToString(i),
				[i, equipId, buttonPoint]()
				{
					if (i >= CassetteManager::instance().getEquipment(equipId).getCassetteList().size())
					{
						return;
					}
					auto itr = CassetteManager::instance().getEquipment(equipId).getCassetteList().begin();
					std::advance(itr, i);

					AdventureManager::instance().openWindow(std::make_unique<CassetteMoveWindow>((*itr), buttonPoint + WINDOW_OFFSET));
				}
			);

			// ボタンの横の位置関係の設定
			if (i > 0)
			{
				ButtonManager::instance().setHorizontalAdjacentButton
				(
					BUTTON_NAME[equipId] + ToString(i - 1),
					BUTTON_NAME[equipId] + ToString(i)
				);
			}
		}

		// ボタンの縦の位置関係
		ButtonManager::instance().setVerticalAdjacentButton
		(
			BUTTON_NAME[ID_A] + ToString(i),
			BUTTON_NAME[ID_B] + ToString(i)
		);
	}

	// 所持ボタンとつなげる
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_A] + ToString(BUTTON_NUM - 1),
		U"Possess0"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_A] + ToString(BUTTON_NUM - 1),
		U"Possess3"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_A] + ToString(BUTTON_NUM - 1),
		U"Possess6"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_B] + ToString(BUTTON_NUM - 1),
		U"Possess9"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_B] + ToString(BUTTON_NUM - 1),
		U"Possess15"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_B] + ToString(BUTTON_NUM - 1),
		U"Possess18"
	);
	ButtonManager::instance().setHorizontalAdjacentButton
	(
		BUTTON_NAME[ID_B] + ToString(BUTTON_NUM - 1),
		U"Possess12"
	);
}


void Kokoha::EquipmentCassetteView::update()
{

}


void Kokoha::EquipmentCassetteView::draw() const
{
	Point drawPoint = BUTTON_POINT[ID_A];

	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		Rect(BUTTON_POINT[ID_A] + BUTTON_SIZE * Point(i, 0), BUTTON_SIZE).drawFrame(1, MyWhite);
		Rect(BUTTON_POINT[ID_B] + BUTTON_SIZE * Point(i, 0), BUTTON_SIZE).drawFrame(1, MyWhite);
	}

	drawCost(drawPoint, ID_A);
	for (const auto& cassettePtr : CassetteManager::instance().getEquipment(ID_A).getCassetteList())
	{
		cassettePtr->getIconTexture().draw(drawPoint);

		drawPoint.x += BUTTON_SIZE.x;
	}

	drawPoint = BUTTON_POINT[ID_B];
	drawCost(drawPoint, ID_B);
	for (const auto& cassettePtr : CassetteManager::instance().getEquipment(ID_B).getCassetteList())
	{
		cassettePtr->getIconTexture().draw(drawPoint);

		drawPoint.x += BUTTON_SIZE.x;
	}
}


void Kokoha::EquipmentCassetteView::drawCost(const Point& pos,const int32 id) const
{
	Point drawPos = pos + COST_POS;

	const int32 COST_LIMIT = RecordManager::instance().getRecord(U"CassetteCount");
	const int32 COST_USED  = CassetteManager::instance().getEquipment(id).getTotalCost();

	FontAsset(U"15")(U"コスト").draw(drawPos + Point(-2, -1));
	drawPos.x += FontAsset(U"15")(U"コスト").region().w;

	TextureAsset(U"Cost")(0, 0, 10, 20).draw(drawPos);
	drawPos.x += 10;

	for (int32 i = 0; i < COST_LIMIT; ++i)
	{
		if (i < COST_USED)
		{
			TextureAsset(U"Cost")(10, 0, 10, 20).draw(drawPos);
		}
		else
		{
			TextureAsset(U"Cost")(20, 0, 10, 20).draw(drawPos);
		}

		drawPos.x += 10;
	}

	TextureAsset(U"Cost")(30, 0, 10, 20).draw(drawPos);
}
