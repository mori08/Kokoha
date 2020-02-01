#include "GameOverState.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"


namespace
{
	// アルファ値変更の比
	constexpr double CHANGE_ALPHA_RATE = 0.05;

	// マスの1辺の長さ
	constexpr int32 SQUARE_SIZE = 32;
	// マスの振動範囲
	constexpr Rect SHAKE_RANGE = Kokoha::getRectFromTwoPoint(Point(-1, -1), Point(+1, +1));

	// テキストを表示し始める時間
	constexpr double DRAW_TEXT_START = 1.2;
	// 次の文字を表示するまでの期間
	constexpr double DRAW_TEXT_SPAN  = 0.18;

	// 選択可能になる時間
	constexpr double SELECT_SECOND = 2.0;
	// 選択ウィンドウ
	constexpr RoundRect SELECT_WINDOW
	(
		Vec2(550, 400) - Vec2(150, 100)/2,
		Vec2(150, 100),
		5
	);

	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(120, 30);
	// 「もう一度」ボタン
	const Kokoha::Button CONTINUE_BUTTON(U"もういちど", Kokoha::getRectFromCenter(Point(550, 380), BUTTON_SIZE));
	// 「あきらめる」ボタン
	const Kokoha::Button GIVEUP_BUTTON  (U"あきらめる", Kokoha::getRectFromCenter(Point(550, 420), BUTTON_SIZE));
	// ボタンのリスト
	const Array<Kokoha::Button> BUTTON_LIST
	{
		CONTINUE_BUTTON,
		GIVEUP_BUTTON
	};
	// カーソルを動かす比
	constexpr double CURSOR_MOVE_RATE = 0.001;
}


Kokoha::GameOverState::GameOverState()
	: mTimeSecond(0)
	, mSquareAlpha(0)
	, mSceneName(none)
	, mCursor(CONTINUE_BUTTON.getRegion())
{
	ButtonManager::instance().clearButtonList();
	for (auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	ButtonManager::instance().setOnClickFunc
	(
		CONTINUE_BUTTON.getName(),
		[this]()
		{
			mSceneName = SceneName::LOAD_GAME;
		}
	);

	ButtonManager::instance().setOnClickFunc
	(
		GIVEUP_BUTTON.getName(),
		[this]()
		{
			mSceneName = SceneName::LOAD_ADVENTURE;
		}
	);

	ButtonManager::instance().setVerticalAdjacentButton
	(
		CONTINUE_BUTTON.getName(),
		GIVEUP_BUTTON.getName()
	);
}


void Kokoha::GameOverState::update()
{
	mTimeSecond += Scene::DeltaTime();

	// マスのアルファ値の変更
	internalDividingPoint(mSquareAlpha, 1.0, CHANGE_ALPHA_RATE);

	if (mTimeSecond < DRAW_TEXT_START) { return; }

	// ボタンの更新
	ButtonManager::instance().update();
	internalDividingPoint
	(
		mCursor.pos,
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_MOVE_RATE
	);
}


void Kokoha::GameOverState::draw() const
{
	// 背景の白
	Scene::Rect().draw(MyWhite);
	
	// 揺れるマス
	for (auto pos : getGridPoint(Rect(Point::Zero(), Scene::Size() / SQUARE_SIZE)))
	{
		Rect(SQUARE_SIZE * pos + RandomPoint(SHAKE_RANGE), SQUARE_SIZE)
			.draw(ColorF(MyBlack).setA(mSquareAlpha));
	}

	if (mTimeSecond < DRAW_TEXT_START) { return; }

	// テキストの表示
	const size_t textLength = (size_t)((mTimeSecond - DRAW_TEXT_START) / DRAW_TEXT_SPAN);
	const String text = String(U"FAILED").substr(0, textLength);
	FontAsset(U"40")(text).drawAt(Scene::CenterF(), MyWhite);

	if (mTimeSecond < SELECT_SECOND) { return; }

	// シーン遷移先の選択
	SELECT_WINDOW.draw(MyBlack).drawFrame(2.0, MyWhite);
	mCursor.draw(MyWhite);
	for (const auto& button : BUTTON_LIST)
	{
		Color color = ButtonManager::instance().getSelectedButton().getName() == button.getName()
			? MyBlack
			: MyWhite;
		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}


Optional<SceneName> Kokoha::GameOverState::isChangeAbleScene() const
{
	return mSceneName;
}
