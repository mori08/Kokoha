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
	constexpr RectF INIT_CURSOR(430, 30, 60, 60);

	// �����J�Z�b�g�̕`��ʒu
	constexpr Point POSSESS_POS(400, 100);
	// �����J�Z�b�g�̕`��ʒu
	constexpr Point EQUIPMENT_POS(200, 100);

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.00005;

	// �J�[�\���̊p�̔��a
	constexpr double CURSOR_RADIUS = 3;
}


Kokoha::SetupWindow::SetupWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), BOARD_SIZE))
	, mCursor(INIT_CURSOR, INIT_CURSOR.pos)
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
	mEquipmentCassetteView.setButton();
	
	// �I���{�^���̐ݒ�
	ButtonManager::instance().setSelectedButton(mSelectedButtonName);
}


void Kokoha::SetupWindow::update()
{
	// �J�[�\���̈ړ�
	internalDividingPoint
	(
		mCursor.first.pos,
		mCursor.second,
		CURSOR_RATE
	);
}


void Kokoha::SetupWindow::selectedUpdate()
{
	// �E�B���h�E�����
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// �J�Z�b�g�ꗗ�̍X�V
	mPossessCassetteView.update();
	mEquipmentCassetteView.update();

	mCursor.second = ButtonManager::instance().getSelectedButton().getRegion().pos;
	mSelectedButtonName = ButtonManager::instance().getSelectedButton().getName();
	ButtonManager::instance().update();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	RoundRect(mCursor.first, CURSOR_RADIUS).draw(Color(MyWhite, 0x80));
	
	// �J�Z�b�g�ꗗ�̍X�V
	mPossessCassetteView.draw();
	mEquipmentCassetteView.draw();
	
	// �����e�L�X�g
	FontAsset(U"20")(U"��������").draw(Point(340, 40)).drawFrame(1, MyWhite);
	FontAsset(U"20")(U"�����т`").draw(Point(100, 110)).drawFrame(1, MyWhite);
	FontAsset(U"20")(U"�����тa").draw(Point(100, 230)).drawFrame(1, MyWhite);
}
