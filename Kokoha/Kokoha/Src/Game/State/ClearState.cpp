#include "ClearState.h"
#include "InfoState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"
#include "../../Record/RecordManager.h"
#include "../../Adventure/AdventureManager.h"
#include "../../Adventure/Window/RewardWindow.h"
#include "../../Event/EventManager.h"


namespace
{
	// アルファ値の変更の比
	constexpr double CHANGE_ALPHA_RATE = 0.01;

	// 光を表示し始める時間
	constexpr double LIGHT_START_SECOND = 1.0;
	// 光の移動の比
	constexpr double LIGHT_MOVE_RATE = 0.3;
	// 光の中心との距離の最大値
	constexpr double MAX_RADIUS = 200.0;
	// 光の範囲
	constexpr RoundRect LIGHT_REGION(Point(320, 240) - Size(240, 60) / 2, Size(240, 60), 10);
	// 光の広がり方
	constexpr double LIGHT_BLUR = 10.0;
	// 光の数
	constexpr int32 LIGHT_NUM = 12;

	// フェードアウト
	constexpr double FADEOUT_SECOND = 5.0;

	// シーン遷移
	constexpr double CHANGE_STATE_SECOND = 6.0;
}


Kokoha::ClearState::ClearState()
	: mTimeSecond(0)
	, mBackAlpha(0)
	, mLightAlpha(0)
	, mRadius(0)
	, mFadeOutAlpha(0)
{
	RecordManager::instance().setRecord(GameManager::instance().getName(), 1);
}


void Kokoha::ClearState::update()
{
	// 時間経過
	mTimeSecond += Scene::DeltaTime();

	// 背景のアルファ値の変更
	internalDividingPoint(mBackAlpha, 1.0, CHANGE_ALPHA_RATE);

	if (mTimeSecond < LIGHT_START_SECOND) { return; }

	// 光のアルファ値の変更
	internalDividingPoint(mLightAlpha, 1.0, CHANGE_ALPHA_RATE);
	
	// 光の描画位置の変更
	internalDividingPoint(mRadius, MAX_RADIUS, LIGHT_MOVE_RATE);

	if (mTimeSecond < FADEOUT_SECOND) { return; }

	// フェードアウト
	internalDividingPoint(mFadeOutAlpha, 1.0, CHANGE_ALPHA_RATE);
}


void Kokoha::ClearState::draw() const
{
	GameManager::instance().draw();

	const ColorF black = ColorF(MyBlack).setA(mBackAlpha);
	const ColorF white = ColorF(MyWhite).setA(mLightAlpha);

	// 背景を少しずつ黒くする
	Scene::Rect().draw(black);

	if (mTimeSecond < LIGHT_START_SECOND) { return; }

	// 中心を明るく
	LIGHT_REGION.drawShadow(Vec2::Zero(), LIGHT_BLUR, 0, white);

	// テキストの表示
	FontAsset(U"40")(U"SUCCESS").drawAt(Scene::CenterF(), black);

	// 光の玉を中心からとばす
	for (int32 i = 0; i < LIGHT_NUM; ++i)
	{
		const double angle = Math::TwoPi * i / LIGHT_NUM;
		const Vec2   direction(Sin(angle), Cos(angle));

		Circle(Scene::CenterF() + mRadius * direction, 10)
			.drawShadow(Vec2::Zero(), 10, 0, white);
	}

	Scene::Rect().draw(ColorF(MyBlack).setA(mFadeOutAlpha));
}


Optional<SceneName> Kokoha::ClearState::isChangeAbleScene() const
{
	if (mTimeSecond < CHANGE_STATE_SECOND) { return none; }
	
	const String stageName = GameManager::instance().getName();
	AdventureManager::instance().clearWindow();
	AdventureManager::instance().openWindow(std::make_unique<RewardWindow>(stageName));

	if (stageName == U"Last")
	{
		if (RecordManager::instance().getRecord(U"Kokoro"))
		{
			EventManager::instance().setEventFileName(U"LastKokoro");
		}
		else
		{
			EventManager::instance().setEventFileName(U"Last");
		}
	}
	else
	{
		EventManager::instance().setEventFileName(stageName);
	}

	return SceneName::LOAD_EVENT;
}
