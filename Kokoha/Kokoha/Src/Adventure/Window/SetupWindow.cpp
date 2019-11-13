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
	constexpr Point POSSESS_POS(370, 100);
}


Kokoha::SetupWindow::SetupWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), BOARD_SIZE))
	, mPossessCassetteView(POSSESS_POS, U"Possess")
{
}


void Kokoha::SetupWindow::select()
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	mPossessCassetteView.setButton();
}


void Kokoha::SetupWindow::update()
{

}


void Kokoha::SetupWindow::selectedUpdate()
{
	mCursor = ButtonManager::instance().getSelectedButton().getRegion();

	mPossessCassetteView.update(CassetteManager::instance().getPossessCassette());

	ButtonManager::instance().update();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	mCursor.draw(Color(MyWhite, 0x80));
	
	mPossessCassetteView.draw(CassetteManager::instance().getPossessCassette());
}
