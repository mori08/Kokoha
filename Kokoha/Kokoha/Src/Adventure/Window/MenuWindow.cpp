#include "MenuWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"


namespace
{
	// MenuWindowのサイズ
	constexpr Size WINDOW_SIZE(200, 200);
	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(150, 30);
	// そうび ボタン
	const Kokoha::Button SETUP_BUTTON (U"そうび", Kokoha::getRectFromCenter(Point(320, 220), BUTTON_SIZE));
	// にっき ボタン
	const Kokoha::Button DIARY_BUTTON (U"にっき", Kokoha::getRectFromCenter(Point(320, 260), BUTTON_SIZE));
	// セーブ ボタン
	const Kokoha::Button RECORD_BUTTON(U"セーブ", Kokoha::getRectFromCenter(Point(320, 300), BUTTON_SIZE));
	// ボタンのリスト
	const Array<Kokoha::Button> BUTTON_LIST
	{
		SETUP_BUTTON,
		DIARY_BUTTON,
		RECORD_BUTTON
	};

	// カーソルの移動の比
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
	// ボタンのリセット
	ButtonManager::instance().clearButtonList();
	
	// ボタンの設定
	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	// ボタンの位置関係の設定
	ButtonManager::instance().setVerticalAdjacentButton
	(
		SETUP_BUTTON.getName(),
		DIARY_BUTTON.getName()
	);
	ButtonManager::instance().setVerticalAdjacentButton
	(
		DIARY_BUTTON.getName(),
		RECORD_BUTTON.getName()
	);

	// 選択中のボタンの設定
	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
}


void Kokoha::MenuWindow::update()
{
	// カーソルの移動
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

	// ボタンの更新
	ButtonManager::instance().update();

	if (InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::MenuWindow::draw() const
{
	drawBoard();

	mCursor.draw(MyWhite);
	
	FontAsset(U"20")(U"メニュー").drawAt(Scene::Center().x, 170);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == mSelectedButton.second)
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}
