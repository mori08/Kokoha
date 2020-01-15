#include "EquipmentCassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../../MyColor.h"
#include "../../../Cassette/CassetteManager.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Adventure/AdventureManager.h"


namespace
{
	// �{�^���̕`��ʒu�̊�ƂȂ�_
	constexpr std::array<Point, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_POINT
	{
		Point(30,150),
		Point(30,270)
	};

	// �{�^���̖��O
	const std::array<String, Kokoha::CassetteManager::EQUIPMENT_NUM> BUTTON_NAME
	{
		U"EquipmentA",
		U"EquipmentB"
	};

	// �{�^���̐�
	constexpr int32 BUTTON_NUM = 6;

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(60, 60);

	// �����`�̂h�c
	constexpr size_t ID_A = 0;
	// �����a�̂h�c
	constexpr size_t ID_B = 1;

	// �E�B���h�E��\��������W�̕␳
	constexpr Point WINDOW_OFFSET(60, -20);
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

	for (const auto& cassettePtr : CassetteManager::instance().getEquipment(ID_A).getCassetteList())
	{
		cassettePtr->getIconTexture().draw(drawPoint);

		drawPoint.x += BUTTON_SIZE.x;
	}

	drawPoint = BUTTON_POINT[ID_B];

	for (const auto& cassettePtr : CassetteManager::instance().getEquipment(ID_B).getCassetteList())
	{
		cassettePtr->getIconTexture().draw(drawPoint);

		drawPoint.x += BUTTON_SIZE.x;
	}
}
