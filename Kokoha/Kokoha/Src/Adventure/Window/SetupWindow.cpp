#include "SetupWindow.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../Cassette/CassetteManager.h"
#include "../../MyColor.h"


namespace
{
	// このウィンドウのサイズ
	constexpr Size BOARD_SIZE(600, 440);
	
	// 所持カセットの描画位置
	constexpr Point POSSESS_POS(400, 100);
	// 装備カセットの描画位置
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
	// ボタンのリセット
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

	// カセット一覧の更新
	mEquipmentCassetteView.update(CassetteManager::instance().getEquipment(mSelectedEquipmentId).getCassetteList(), mSelectedEquipmentId);
	mPossessCassetteView.update(CassetteManager::instance().getPossessCassette(), mSelectedEquipmentId);

	ButtonManager::instance().update();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	mCursor.draw(Color(MyWhite, 0x80));
	
	// カセット一覧の更新
	mEquipmentCassetteView.draw(CassetteManager::instance().getEquipment(mSelectedEquipmentId).getCassetteList());
	mPossessCassetteView.draw(CassetteManager::instance().getPossessCassette());
}
