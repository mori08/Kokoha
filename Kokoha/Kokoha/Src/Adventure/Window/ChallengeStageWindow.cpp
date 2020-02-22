#include "ChallengeStageWindow.h"
#include "SetupWindow.h"
#include "../AdventureManager.h"
#include "../../Input/ButtonManager.h"
#include "../../Game/GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"


namespace
{
	// ウィンドウのサイズ
	constexpr Size WINDOW_SIZE(360, 150);

	// テキストを表示する座標
	constexpr Point TEXT_POS(320, 190);

	// 「アクセス」ボタン
	const Kokoha::Button ACCESS_BUTTON
	(
		U"アクセス",
		Kokoha::getRectFromCenter(Point(320, 250), Size(100, 30))
	);
	// 「そうび」ボタン
	const Kokoha::Button EQUIPMENT_BUTTON
	(
		U"そうび",
		Kokoha::getRectFromCenter(Point(320, 290), Size(100, 30))
	);

	// ボタンのリスト
	const Array<Kokoha::Button> BUTTON_LIST
	{
		ACCESS_BUTTON,
		EQUIPMENT_BUTTON
	};

	// カーソルの移動の比
	constexpr double RATE = 0.005;
}


Kokoha::ChallengeStageWindow::ChallengeStageWindow(const String& stageName)
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
	, mStageName(stageName)
	, mCursor(ACCESS_BUTTON.getRegion())
	, mSelectedButton(ACCESS_BUTTON.getRegion().pos, ACCESS_BUTTON.getName())
{
}


void Kokoha::ChallengeStageWindow::select()
{
	ButtonManager::instance().clearButtonList();

	// ボタンの登録
	ButtonManager::instance().registerButton(ACCESS_BUTTON);
	ButtonManager::instance().registerButton(EQUIPMENT_BUTTON);
	ButtonManager::instance().setVerticalAdjacentButton
	(
		ACCESS_BUTTON.getName(),
		EQUIPMENT_BUTTON.getName()
	);

	// ボタンを押したときの処理の設定
	ButtonManager::instance().setOnClickFunc
	(
		ACCESS_BUTTON.getName(),
		[this]() {
			GameManager::instance().setName(mStageName);
			AdventureManager::instance().setSceneName(SceneName::LOAD_GAME); 
			AdventureManager::instance().clearWindow();
		}
	);
	ButtonManager::instance().setOnClickFunc
	(
		EQUIPMENT_BUTTON.getName(),
		[]() { AdventureManager::instance().openWindow(std::make_unique<SetupWindow>()); }
	);

	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
}


void Kokoha::ChallengeStageWindow::update()
{
	internalDividingPoint
	(
		mCursor.pos,
		mSelectedButton.first,
		RATE
	);
}


void Kokoha::ChallengeStageWindow::selectedUpdate()
{
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	mSelectedButton.first  = ButtonManager::instance().getSelectedButton().getRegion().pos;
	mSelectedButton.second = ButtonManager::instance().getSelectedButton().getName();
	ButtonManager::instance().update();
}


void Kokoha::ChallengeStageWindow::draw() const
{
	drawBoard();

	if (mStageName == U"5-1" || mStageName == U"5-2" || mStageName == U"5-3")
	{
		FontAsset(U"20")(U"このパソコンにアクセスしますか？").drawAt(TEXT_POS, MyWhite);
	}
	else if (mStageName == U"Last")
	{
		FontAsset(U"20")(U"このドアにアクセスしますか？").drawAt(TEXT_POS, MyWhite);
	}
	else
	{
		FontAsset(U"20")(U"このロボットにアクセスしますか？").drawAt(TEXT_POS, MyWhite);
	}

	mCursor.draw(MyWhite);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = button.getName() == mSelectedButton.second
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}
