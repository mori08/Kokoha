#include "RunAwayGoal.h"
#include "../../GameManager.h"


namespace
{
	// 速さ
	constexpr double SPEED = 1.5;

	// 目的地を変更の時間
	constexpr double MAX_CHANGE_GOAL_SECOND = 0.1;

	// 評価値の比率
	constexpr double RATE = 1.5;
}


Kokoha::RunAwayGoal::RunAwayGoal(const Vec2& pos)
	: GameGoal(pos, SPEED)
	, mChangeGoalSecond(0)
{
}


void Kokoha::RunAwayGoal::update()
{
	mChangeGoalSecond -= Scene::DeltaTime();

	if (mChangeGoalSecond < 0)
	{
		mChangeGoalSecond = MAX_CHANGE_GOAL_SECOND;

		mGoal = GameManager::instance().getStageData().getRunAwayPixel(mBody.center);
	}

	GameGoal::update();
}
