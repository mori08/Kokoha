#include "PauseState.h"
#include "PlayingState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"
#include "../../Input/ButtonManager.h"


namespace
{
	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(150, 30);

	// 「つづける」ボタン
	const Kokoha::Button CONTINUE_BUTTON
	(
		U"つづける",
		Kokoha::getRectFromCenter(Point(320, 300), BUTTON_SIZE)
	);
	// 「やりなおす」ボタン
	const Kokoha::Button RELOAD_BUTTON
	(
		U"やりなおす",
		Kokoha::getRectFromCenter(Point(320, 350), BUTTON_SIZE)
	);
	// 「あきらめる」ボタン
	const Kokoha::Button GIVEUP_BUTTON
	(
		U"あきらめる",
		Kokoha::getRectFromCenter(Point(320, 400), BUTTON_SIZE)
	);

	// ボタンリスト
	const Array<Kokoha::Button> BUTTON_LIST
	{
		CONTINUE_BUTTON,
		RELOAD_BUTTON,
		GIVEUP_BUTTON
	};

	// カーソルの移動の比
	constexpr double CURSOR_RATE = 0.005;

	// テキストの表示
	constexpr Point TEXT_POS(320, 150);
}



Kokoha::PauseState::PauseState(std::unique_ptr<GameState> preState)
	: mPreState(std::move(preState))
	, mSceneName(none)
	, mCursor(CONTINUE_BUTTON.getRegion())
{
	// ボタンのリセット
	ButtonManager::instance().clearButtonList();

	// ボタンの設定
	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	// ボタンの位置関係の設定
	for (size_t i = 0; i < BUTTON_LIST.size(); ++i)
	{
		ButtonManager::instance().setVerticalAdjacentButton
		(
			BUTTON_LIST[i].getName(),
			BUTTON_LIST[(i + 1) % BUTTON_LIST.size()].getName()
		);
	}

	// ボタンを押したときの処理の設定
	ButtonManager::instance().setOnClickFunc
	(
		CONTINUE_BUTTON.getName(),
		[this]() { GameManager::instance().setState(std::move(mPreState)); }
	);
	ButtonManager::instance().setOnClickFunc
	(
		RELOAD_BUTTON.getName(),
		[this]() { mSceneName = SceneName::LOAD_GAME; }
	);
	ButtonManager::instance().setOnClickFunc
	(
		GIVEUP_BUTTON.getName(),
		[this]() { mSceneName = SceneName::ADVENTURE; }
	);

	// 選択中のボタンの設定
	ButtonManager::instance().setSelectedButton(CONTINUE_BUTTON.getName());
}


void Kokoha::PauseState::update()
{
	// カーソルの移動
	internalDividingPoint
	(
		mCursor.pos,
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_RATE
	);

	// キャンセルボタンで続ける
	if (InputManager::instance().cancel())
	{
		GameManager::instance().setState(std::move(mPreState));
		return;
	}

	// ボタンの更新
	ButtonManager::instance().update();
}


void Kokoha::PauseState::draw() const
{
	mCursor.draw(MyWhite);

	FontAsset(U"30")(U"ポーズ").drawAt(TEXT_POS, MyWhite);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == ButtonManager::instance().getSelectedButton().getName())
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}


Optional<SceneName> Kokoha::PauseState::isChangeAbleScene() const
{
	return mSceneName;
}
