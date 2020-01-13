#include "CassetteMoveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Cassette/CassetteManager.h"
#include "../../Input/ButtonManager.h"
#include "../../MyColor.h"


namespace
{
	// このウィンドウのサイズ
	constexpr Size BOARD_SIZE(120, 120);
	// 座標の補正
	constexpr Point OFFSET(30, 30);

	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(100, 30);

	// カーソルの移動の比
	constexpr double CURSOR_RATE = 0.001;
}


Kokoha::CassetteMoveWindow::CassetteMoveWindow(const CassettePtr& cassette, const Point& pos)
	: AdventureWindow(Rect(pos + OFFSET, BOARD_SIZE))
	, mCassettePtr(cassette)
{
	Rect region = getRectFromCenter(mWindowBoard.center().asPoint(), BUTTON_SIZE);
	region.y -= BUTTON_SIZE.y;

	// 未装備のカセット
	if (cassette->getState() == Cassette::POSSESS_STATE)
	{
		// 「Ａにそうび」ボタン
		Button buttonA(U"Ａにそうび", region);
		buttonA.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(Cassette::EQUIPMENT_A_STATE).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		region.y += BUTTON_SIZE.y;

		// 「Ｂにそうび」
		Button buttonB(U"Ｂにそうび", region);
		buttonB.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(Cassette::EQUIPMENT_B_STATE).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		mButtonList.emplace_back(buttonA);
		mButtonList.emplace_back(buttonB);
	}

	// 装備済のカセット
	else
	{
		// 「はずす」ボタン
		Button buttonHazusu(U"はずす", region);
		buttonHazusu.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(cassette->getState()).removeCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		region.y += BUTTON_SIZE.y;

		// 「つけかえる」ボタン
		Button buttonTsukekaeru(U"つけかえる", region);
		buttonTsukekaeru.setOnClickFunc
		(
			[cassette]()
			{
				CassetteManager::instance().getEquipment(cassette->getState()).removeCassette(cassette);
				CassetteManager::instance().getEquipment(cassette->getState()+1).addCassette(cassette);
				AdventureManager::instance().closeWindow();
			}
		);

		mButtonList.emplace_back(buttonHazusu);
		mButtonList.emplace_back(buttonTsukekaeru);
	}

	region.y += BUTTON_SIZE.y; mButtonList.emplace_back(U"くわしく", region);

	mSelectedButton = { region.pos, U"くわしく" };
	mCursor = region;
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

	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
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
