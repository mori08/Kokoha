#include "MenuWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"

// ���E�B���h�E
#include "SetupWindow.h"
#include "SaveWindow.h"


namespace
{
	// MenuWindow�̃T�C�Y
	constexpr Size WINDOW_SIZE(200, 200);
	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(150, 30);
	// ������ �{�^��
	const Kokoha::Button SETUP_BUTTON (U"������", Kokoha::getRectFromCenter(Point(320, 230), BUTTON_SIZE));
	// �Z�[�u �{�^��
	const Kokoha::Button RECORD_BUTTON(U"�Z�[�u", Kokoha::getRectFromCenter(Point(320, 290), BUTTON_SIZE));
	// �{�^���̃��X�g
	const Array<Kokoha::Button> BUTTON_LIST
	{
		SETUP_BUTTON,
		RECORD_BUTTON
	};

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.001;
}


Kokoha::MenuWindow::MenuWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
	, mSelectedButton(SETUP_BUTTON.getRegion().pos, SETUP_BUTTON.getName())
	, mCursor(SETUP_BUTTON.getRegion())
{
}


void Kokoha::MenuWindow::select()
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();
	
	// �{�^���̐ݒ�
	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	// �{�^���̈ʒu�֌W�̐ݒ�
	ButtonManager::instance().setVerticalAdjacentButton
	(
		SETUP_BUTTON.getName(),
		RECORD_BUTTON.getName()
	);

	// �{�^�����������Ƃ��̏����̐ݒ�
	ButtonManager::instance().setOnClickFunc
	(
		SETUP_BUTTON.getName(),
		[](){ AdventureManager::instance().openWindow(std::make_unique<SetupWindow>()); }
	);
	ButtonManager::instance().setOnClickFunc
	(
		RECORD_BUTTON.getName(),
		[](){ AdventureManager::instance().openWindow(std::make_unique<SaveWindow>()); }
	);

	// �I�𒆂̃{�^���̐ݒ�
	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
}


void Kokoha::MenuWindow::update()
{
	// �J�[�\���̈ړ�
	internalDividingPoint
	(
		mCursor.pos,
		mSelectedButton.first,
		CURSOR_RATE
	);
}


void Kokoha::MenuWindow::selectedUpdate()
{
	mSelectedButton.first  = ButtonManager::instance().getSelectedButton().getRegion().pos;
	mSelectedButton.second = ButtonManager::instance().getSelectedButton().getName();

	// �E�B���h�E�����
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// �{�^���̍X�V
	ButtonManager::instance().update();
}


void Kokoha::MenuWindow::draw() const
{
	drawBoard();

	mCursor.draw(MyWhite);
	
	FontAsset(U"20")(U"���j���[").drawAt(Scene::Center().x, 170);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == mSelectedButton.second)
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}
