#include "RandomGoal.h"
#include "../../GameManager.h"


namespace Kokoha
{
	// 速さ
	constexpr double SPEED = 0.5;

	// 目的地を変更する距離
	constexpr double CHANGE_GOAL_DISTANCE = 2.0;

	// 評価値の比
	constexpr double RATE = 1.2;

	// 候補点の個数
	constexpr int32 POINT_NUM = 3;
}


Kokoha::RandomGoal::RandomGoal(const Vec2& pos)
	: GameGoal(pos, SPEED)
{
}


void Kokoha::RandomGoal::update()
{
	// 目的地に充分に近づいたとき 目的地変更
	if ((mBody.center - mGoal).length() < CHANGE_GOAL_DISTANCE)
	{
		double minDistance = Inf<double>;
		Vec2   playerPos   = GameManager::instance().getPlayerPos();

		// √N 個のランダムに選ばれた候補点を考える
		for (int32 i = 0; i < POINT_NUM; ++i)
		{
			Vec2 nextGoal
				= RandomVec2(RectF(Vec2::Zero(), StageData::SQUARE_SIZE * Vec2(StageData::WIDTH, StageData::HEIGHT)));

			if (!GameManager::instance().getStageData().isWalkAble(nextGoal)) { continue; }

			double distance
				= GameManager::instance().getStageData().getDistance(mBody.center, nextGoal)
				- RATE*GameManager::instance().getStageData().getDistance(playerPos   , nextGoal);

			if (distance > minDistance) { continue; }

			minDistance = distance;
			mGoal       = nextGoal;
		}
	}

	GameGoal::update();
}
