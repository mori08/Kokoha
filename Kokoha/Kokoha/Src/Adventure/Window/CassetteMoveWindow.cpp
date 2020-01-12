#include "CassetteMoveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Cassette/CassetteManager.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"


namespace
{
	// このウィンドウのサイズ
	constexpr Size BOARD_SIZE(200, 200);
	// 座標の補正
	constexpr Point OFFSET(30, 30);

	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(100, 30);

	// カーソルの移動の比
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

	// つけるボタン (カセットが装備されていないとき)
	if (cassette->getState() == Cassette::POSSESS_STATE)
	{
		Button button(U"そうび", region);
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
	// はずすボタン (カセットが選択中の装備にあるとき)
	else if (cassette->getState() == selectedId)
	{
		Button button(U"はずす", region);
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
	// つけかえるボタン (カセットが選択していない装備にあるとき)
	else
	{
		Button button(U"つけかえる", region);
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

	region.y += BUTTON_SIZE.y; mButtonList.emplace_back(U"くわしく", region);

	mSelectedButton = { region.pos, U"くわしく" };
}


void Kokoha::CassetteMoveWindow::select()
{
	// ボタンのリセット
	ButtonManager::instance().clearButtonList();

	// ボタンの設定
	for (const auto& button : mButtonList)
	{
		ButtonManager::instance().registerButton(button);
	}

	// ボタンの位置関係の設定
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
	// カーソルの移動
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

	// ウィンドウを閉じる
	if (InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// ボタンの更新
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
