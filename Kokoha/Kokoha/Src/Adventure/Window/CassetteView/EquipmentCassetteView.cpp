#include "EquipmentCassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../../MyColor.h"
#include "../../../Cassette/CassetteManager.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Adventure/AdventureManager.h"
#include "../../../Record/RecordManager.h"


namespace
{
	// �{�^���̕`��ʒu�̊�ƂȂ�_
	constexpr std::array<Point, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_POINT
	{
		Point(120,150),
		Point(120,270)
	};

	// �{�^���̖��O
	const std::array<String, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_NAME
	{
		U"EquipmentA",
		U"EquipmentB"
	};

	// �{�^���̐�
	constexpr int32 BUTTON_NUM = 3;

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(60, 60);

	// �����`�̂h�c
	constexpr size_t ID_A = 0;
	// �����a�̂h�c
	constexpr size_t ID_B = 1;

	// �E�B���h�E��\��������W�̕␳
	constexpr Point WINDOW_OFFSET(60, -20);

	// �R�X�g�\���̍��W
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

			// �{�^���̐ݒ�
			ButtonManager::instance().registerButton
			(
				BUTTON_NAME[equipId] + ToString(i),
				Rect(buttonPoint, BUTTON_SIZE)
			);

			// �{�^�����������Ƃ��̏����̐ݒ�
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

			// �{�^���̉��̈ʒu�֌W�̐ݒ�
			if (i > 0)
			{
				ButtonManager::instance().setHorizontalAdjacentButton
				(
					BUTTON_NAME[equipId] + ToString(i - 1),
					BUTTON_NAME[equipId] + ToString(i)
				);
			}
		}

		// �{�^���̏c�̈ʒu�֌W
		ButtonManager::instance().setVerticalAdjacentButton
		(
			BUTTON_NAME[ID_A] + ToString(i),
			BUTTON_NAME[ID_B] + ToString(i)
		);
	}

	// �����{�^���ƂȂ���
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

	FontAsset(U"15")(U"�R�X�g").draw(drawPos + Point(-2, -1));
	drawPos.x += FontAsset(U"15")(U"�R�X�g").region().w;

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
