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
	constexpr RectF INIT_CURSOR(430, 30, 60, 60);

	// 所持カセットの描画位置
	constexpr Point POSSESS_POS(400, 100);
	// 装備カセットの描画位置
	constexpr Point EQUIPMENT_POS(200, 100);

	// カーソルの移動の比
	constexpr double CURSOR_RATE = 0.00005;

	// カーソルの角の半径
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
	// ボタンのリセット
	ButtonManager::instance().clearButtonList();

	// ボタンの設定
	mPossessCassetteView.setButton();
	mEquipmentCassetteView.setButton();
	
	// 選択ボタンの設定
	ButtonManager::instance().setSelectedButton(mSelectedButtonName);
}


void Kokoha::SetupWindow::update()
{
	// カーソルの移動
	internalDividingPoint
	(
		mCursor.first.pos,
		mCursor.second,
		CURSOR_RATE
	);
}


void Kokoha::SetupWindow::selectedUpdate()
{
	// ウィンドウを閉じる
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// カセット一覧の更新
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
	
	// カセット一覧の更新
	mPossessCassetteView.draw();
	mEquipmentCassetteView.draw();
	
	// 説明テキスト
	FontAsset(U"20")(U"もちもの").draw(Point(340, 40)).drawFrame(1, MyWhite);
	FontAsset(U"20")(U"そうびＡ").draw(Point(100, 110)).drawFrame(1, MyWhite);
	FontAsset(U"20")(U"そうびＢ").draw(Point(100, 230)).drawFrame(1, MyWhite);
}
