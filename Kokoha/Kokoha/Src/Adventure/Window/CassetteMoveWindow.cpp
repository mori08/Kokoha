#include "CassetteMoveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Cassette/CassetteManager.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"


namespace
{
	// ���̃E�B���h�E�̃T�C�Y
	constexpr Size BOARD_SIZE(120, 120);
	// ���W�̕␳
	constexpr Point OFFSET(30, 30);

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(100, 30);

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.001;
}


Kokoha::CassetteMoveWindow::CassetteMoveWindow(const CassettePtr& cassette, const Point& pos)
	: AdventureWindow(Rect(pos + OFFSET, BOARD_SIZE))
	, mCassettePtr(cassette)
{
	Rect region = getRectFromCenter(mWindowBoard.center().asPoint(), BUTTON_SIZE);
	region.y -= BUTTON_SIZE.y;

	// �������̃J�Z�b�g
	if (cassette->getState() == Cassette::POSSESS_STATE)
	{
		// �u�`�ɂ����сv�{�^��
		Button buttonA(U"�`�ɂ�����", region);
		buttonA.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(Cassette::EQUIPMENT_A_STATE).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		region.y += BUTTON_SIZE.y;

		// �u�a�ɂ����сv
		Button buttonB(U"�a�ɂ�����", region);
		buttonB.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(Cassette::EQUIPMENT_B_STATE).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		mButtonList.emplace_back(buttonA);
		mButtonList.emplace_back(buttonB);
	}

	// �����ς̃J�Z�b�g
	else
	{
		// �u�͂����v�{�^��
		Button buttonHazusu(U"�͂���", region);
		buttonHazusu.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(cassette->getState()).removeCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		region.y += BUTTON_SIZE.y;

		// �u��������v�{�^��
		Button buttonTsukekaeru(U"��������", region);
		buttonTsukekaeru.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(cassette->getState()).removeCassette(cassette);
				CassetteManager::instance().getEquipment(cassette->getState()+1).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		mButtonList.emplace_back(buttonHazusu);
		mButtonList.emplace_back(buttonTsukekaeru);
	}

	region.y += BUTTON_SIZE.y; mButtonList.emplace_back(U"���킵��", region);

	mSelectedButton = { region.pos, U"���킵��" };
	mCursor = region;
}


void Kokoha::CassetteMoveWindow::select()
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	// �{�^���̐ݒ�
	for (const auto& button : mButtonList)
	{
		ButtonManager::instance().registerButton(button);
	}

	// �{�^���̈ʒu�֌W�̐ݒ�
	for (size_t i = 0; i < mButtonList.size(); ++i)
	{
		ButtonManager::instance().setVerticalAdjacentButton
		(
			mButtonList[i].getName(),
			mButtonList[(i + 1) % mButtonList.size()].getName()
		);
	}

	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
}


void Kokoha::CassetteMoveWindow::update()
{
	// �J�[�\���̈ړ�
	internalDividingPoint
	(
		mCursor.pos,
		mSelectedButton.first,
		CURSOR_RATE
	);
}


void Kokoha::CassetteMoveWindow::selectedUpdate()
{
	mSelectedButton.first  = ButtonManager::instance().getSelectedButton().getRegion().pos;
	mSelectedButton.second = ButtonManager::instance().getSelectedButton().getName();

	// �E�B���h�E�����
	if (InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// �{�^���̍X�V
	ButtonManager::instance().update();
}


void Kokoha::CassetteMoveWindow::draw() const
{
	drawBoard();

	mCursor.draw(MyWhite);

	for (const auto& button : mButtonList)
	{
		Color color = (button.getName() == mSelectedButton.second)
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}
