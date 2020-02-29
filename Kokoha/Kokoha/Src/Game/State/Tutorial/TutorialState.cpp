#include "TutorialState.h"
#include "../../GameManager.h"
#include "../../../Input/InputManager.h"
#include "../../../MyLibrary.h"
#include "../../../MyColor.h"


namespace
{
	// テキストの表示間隔
	constexpr double DRAW_TEXT_SPAN = 0.2;

	// 達成率の変更比率
	constexpr double CHANGE_RATE = 0.01;

	// 達成率表示のゲージの長さ
	constexpr double GAGE_LENGTH = 128;

	// 達成率表示のゲージの右上座標
	constexpr Vec2 GAGE_POS(16, 170);

	// 達成率表示のゲージの右上座標
	constexpr Vec2 CONTROL_POS(0, 120);
}


Kokoha::TutorialState::TutorialState(const String& mission, const String& control)
	: mMissionText(mission)
	, mControlText(control)
	, mTimeSecond(0)
	, mAchieveRate(0)
{
}


void Kokoha::TutorialState::update()
{
	mTimeSecond += Scene::DeltaTime();
}


void Kokoha::TutorialState::draw() const
{
	GameManager::instance().draw();

	size_t TEXT_LENGTH = (size_t)(mTimeSecond / DRAW_TEXT_SPAN);

	FontAsset(U"20")(mMissionText.substr(0, TEXT_LENGTH)).draw(Point::Zero(), MyWhite);

	FontAsset(U"20")(mControlText.substr(0, TEXT_LENGTH)).draw(CONTROL_POS, MyWhite);

	RectF(GAGE_POS, Vec2(mAchieveRate * GAGE_LENGTH, 2.0)).draw(MyWhite);
}


void Kokoha::TutorialState::updateAchieveRate(double value)
{
	internalDividingPoint
	(
		mAchieveRate,
		Max(0.0, (Min(value, 1.0))),
		CHANGE_RATE
	);
}
