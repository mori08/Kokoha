#include "SetupWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../Cassette/CassetteManager.h"
#include "../../MyColor.h"


namespace
{
	// ���̃E�B���h�E�̃T�C�Y
	constexpr Size BOARD_SIZE(600, 440);
	
	// �J�[�\���̏����͈�
	constexpr RectF INIT_CURSOR(400, 60, 60, 60);

	// �����J�Z�b�g�̕`��ʒu
	constexpr Point POSSESS_POS(400, 100);
	// �����J�Z�b�g�̕`��ʒu
	constexpr Point EQUIPMENT_POS(200, 100);
}


Kokoha::SetupWindow::SetupWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), BOARD_SIZE))
	, mCursor(INIT_CURSOR)
	, mSelectedButtonName(U"Possess0")
	, mPossessCassetteView()
{
}


void Kokoha::SetupWindow::select()
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	// �{�^���̐ݒ�
	mPossessCassetteView.setButton();

	// �I���{�^���̐ݒ�
	ButtonManager::instance().setSelectedButton(mSelectedButtonName);
}


void Kokoha::SetupWindow::update()
{
	
}


void Kokoha::SetupWindow::selectedUpdate()
{
	// �E�B���h�E�����
	if (InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// �J�Z�b�g�ꗗ�̍X�V
	mPossessCassetteView.update();

	ButtonManager::instance().update();
	mCursor = ButtonManager::instance().getSelectedButton().getRegion();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	mCursor.draw(Color(MyWhite, 0x80));
	
	// �J�Z�b�g�ꗗ�̍X�V
	mPossessCassetteView.draw();
}
