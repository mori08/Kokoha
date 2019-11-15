#include "SetupWindow.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../Cassette/CassetteManager.h"
#include "../../MyColor.h"


namespace
{
	// ���̃E�B���h�E�̃T�C�Y
	constexpr Size BOARD_SIZE(600, 440);
	
	// �����J�Z�b�g�̕`��ʒu
	constexpr Point POSSESS_POS(400, 100);
	// �����J�Z�b�g�̕`��ʒu
	constexpr Point EQUIPMENT_POS(200, 100);
}


Kokoha::SetupWindow::SetupWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), BOARD_SIZE))
	, mSelectedEquipmentId(Cassette::EQUIPMENT_A_STATE)
	, mPossessCassetteView(POSSESS_POS, U"Possess")
	, mEquipmentCassetteView(EQUIPMENT_POS, U"Equipment")
	, mSelectedButtonName(U"Equipment0")
{
}


void Kokoha::SetupWindow::select()
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	mEquipmentCassetteView.setButton();

	mPossessCassetteView.setButton();

	ButtonManager::instance().setSelectedButton(mSelectedButtonName);
}


void Kokoha::SetupWindow::update()
{

}


void Kokoha::SetupWindow::selectedUpdate()
{
	mSelectedButtonName = ButtonManager::instance().getSelectedButton().getName();

	mCursor = ButtonManager::instance().getSelectedButton().getRegion();

	// �J�Z�b�g�ꗗ�̍X�V
	mEquipmentCassetteView.update(CassetteManager::instance().getEquipment(mSelectedEquipmentId).getCassetteList(), mSelectedEquipmentId);
	mPossessCassetteView.update(CassetteManager::instance().getPossessCassette(), mSelectedEquipmentId);

	ButtonManager::instance().update();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	mCursor.draw(Color(MyWhite, 0x80));
	
	// �J�Z�b�g�ꗗ�̍X�V
	mEquipmentCassetteView.draw(CassetteManager::instance().getEquipment(mSelectedEquipmentId).getCassetteList());
	mPossessCassetteView.draw(CassetteManager::instance().getPossessCassette());
}
