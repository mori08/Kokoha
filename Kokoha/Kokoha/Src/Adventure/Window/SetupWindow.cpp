#include "SetupWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../Cassette/CassetteManager.h"
#include "../../MyColor.h"


namespace
{
	// このウィンドウのサイズ
	constexpr Size BOARD_SIZE(600, 440);
	
	// カーソルの初期範囲
	constexpr RectF INIT_CURSOR(400, 60, 60, 60);

	// 所持カセットの描画位置
	constexpr Point POSSESS_POS(400, 100);
	// 装備カセットの描画位置
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
	// ボタンのリセット
	ButtonManager::instance().clearButtonList();

	// ボタンの設定
	mPossessCassetteView.setButton();

	// 選択ボタンの設定
	ButtonManager::instance().setSelectedButton(mSelectedButtonName);
}


void Kokoha::SetupWindow::update()
{
	
}


void Kokoha::SetupWindow::selectedUpdate()
{
	// ウィンドウを閉じる
	if (InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// カセット一覧の更新
	mPossessCassetteView.update();

	ButtonManager::instance().update();
	mCursor = ButtonManager::instance().getSelectedButton().getRegion();
}


void Kokoha::SetupWindow::draw() const
{
	drawBoard();

	mCursor.draw(Color(MyWhite, 0x80));
	
	// カセット一覧の更新
	mPossessCassetteView.draw();
}
