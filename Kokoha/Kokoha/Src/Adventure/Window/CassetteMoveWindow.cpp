#include "CassetteMoveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Cassette/CassetteManager.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"


namespace
{
	// ���̃E�B���h�E�̃T�C�Y
	constexpr Size BOARD_SIZE(200, 200);
	// ���W�̕␳
	constexpr Point OFFSET(30, 30);

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(100, 30);

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.001;
}


Kokoha::CassetteMoveWindow::CassetteMoveWindow(const CassettePtr& cassette, const Point& pos, int32 selectedId)
	: AdventureWindow(Rect(pos + OFFSET, BOARD_SIZE))
	, mCassettePtr(cassette)
	, mSelectedEquipmentId(selectedId)
{
	Rect region = getRectFromCenter(mWindowBoard.center().asPoint(), BUTTON_SIZE);
	region.y -= BUTTON_SIZE.y;

	mCursor = region;

	// ����{�^�� (�J�Z�b�g����������Ă��Ȃ��Ƃ�)
	if (cassette->getState() == Cassette::POSSESS_STATE)
	{
		Button button(U"������", region);
		button.setOnClickFunc
		(
			[selectedId, cassette]()
			{
				CassetteManager::instance().getEquipment(selectedId).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);
		mButtonList.emplace_back(button);
	}
	// �͂����{�^�� (�J�Z�b�g���I�𒆂̑����ɂ���Ƃ�)
	else if (cassette->getState() == selectedId)
	{
		Button button(U"�͂���", region);
		button.setOnClickFunc
		(
			[selectedId, cassette]()
			{
				CassetteManager::instance().getEquipment(selectedId).removeCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);
		mButtonList.emplace_back(button);
	}
	// ��������{�^�� (�J�Z�b�g���I�����Ă��Ȃ������ɂ���Ƃ�)
	else
	{
		Button button(U"��������", region);
		button.setOnClickFunc
		(
			[selectedId, cassette]()
			{
				CassetteManager::instance().getEquipment(cassette->getState()).removeCassette(cassette);
				CassetteManager::instance().getEquipment(selectedId).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);
		mButtonList.emplace_back(button);
	}

	region.y += BUTTON_SIZE.y; mButtonList.emplace_back(U"���킵��", region);

	mSelectedButton = { region.pos, U"���킵��" };
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
