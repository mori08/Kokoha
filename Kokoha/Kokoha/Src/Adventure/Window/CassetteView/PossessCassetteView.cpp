#include "PossessCassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../AdventureManager.h"
#include "../../../MyColor.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Cassette/CassetteManager.h"


namespace
{
	// �`��̊�_
	constexpr Point DRAW_POINT(430, 30);

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(60, 60);

	// �E�B���h�E��\��������W�̕␳
	constexpr Point WINDOW_OFFSET(-130, -20);

	// �{�^���̖��O
	const String BUTTON_NAME(U"Possess");

	// �A�C�R���̗�
	constexpr int32 ICON_COLUMN = 3;
}


void Kokoha::PossessCassetteView::setButton()const
{
	for (int32 i = 0; i < CassetteManager::instance().getCassetteList().size(); ++i)
	{
		Point buttonPoint
			= DRAW_POINT + BUTTON_SIZE * Point(i % ICON_COLUMN, i / ICON_COLUMN);

		// �{�^���̐ݒ�
		ButtonManager::instance().registerButton
		(
			BUTTON_NAME + ToString(i),
			Rect(buttonPoint, BUTTON_SIZE)
		);

		// �{�^�����������Ƃ��̏����̐ݒ�
		ButtonManager::instance().setOnClickFunc
		(
			BUTTON_NAME + ToString(i),
			[i, buttonPoint]()
			{
				CassettePtr cassettePtr = CassetteManager::instance().getCassetteList()[i];
				
				if (cassettePtr->getState() == Cassette::NO_POSSESS_STATE) { return; }

				AdventureManager::instance().openWindow(std::make_unique<CassetteMoveWindow>(cassettePtr, buttonPoint + WINDOW_OFFSET));
			}
		);

		// �{�^���̏c�̈ʒu�֌W�̐ݒ�
		if (i >= ICON_COLUMN)
		{
			ButtonManager::instance().setVerticalAdjacentButton
			(
				BUTTON_NAME + ToString(i - ICON_COLUMN),
				BUTTON_NAME + ToString(i)
			);
		}

		// �{�^���̉��̈ʒu�֌W�̐ݒ�
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

		Rect(drawIconPoint, BUTTON_SIZE).drawFrame(1, MyWhite);

		int32 state = CassetteManager::instance().getCassetteList()[i]->getState();

		if (state == Cassette::NO_POSSESS_STATE)
		{
			continue;
		}

		Color alpha = (state == Cassette::POSSESS_STATE) ? (Alpha(0xFF)) : (Alpha(0xA0));

		CassetteManager::instance().getCassetteList()[i]->getIconTexture().draw(drawIconPoint, alpha);
	}
}
