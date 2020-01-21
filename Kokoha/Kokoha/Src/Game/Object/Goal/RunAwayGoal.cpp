#include "RunAwayGoal.h"
#include "../../GameManager.h"


namespace
{
	// 速さ
	constexpr double SPEED = 1.0;

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

		double minDistance = Inf<double>;

		for (const auto& i : GameManager::instance().getStageData().getCornerGraphEdgeList(mBody.center))
		{
			Vec2 pos = StageData::integerToPixel(i);

			double distance = getDistancePoint(pos);

			if (distance > minDistance) { continue; }

			minDistance = distance;
			mGoal       = pos;
		}
	}

	GameGoal::update();
}


double Kokoha::RunAwayGoal::getDistancePoint(const Vec2& pos)
{
	const Vec2& playerPos = GameManager::instance().getPlayerPos();

	const double myDistance     = GameManager::instance().getStageData().getDistance(mBody.center, pos);
	const double playerDistance = GameManager::instance().getStageData().getDistance(playerPos   , pos);

	return myDistance - RATE * playerDistance;
}
