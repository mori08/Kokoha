#include "GameGoalKey.h"
#include "../../../GameManager.h"


namespace
{
	// 半径
	constexpr double RADIUS = 8;

	// 速さ
	constexpr double SPEED = 1.2;

	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(24, 24);

	// 候補座標の数
	constexpr int32 RANDOM_POS_NUM = 20;

	// 目的地変更の時間
	constexpr std::pair<double, double> CHANGE_GOAL_SECOND = { 3.0,5.0 };
}


Kokoha::GameGoalKey::GameGoalKey(const Vec2& pos)
	: GameObject(Circle(pos, RADIUS), ObjectType::KEY)
	, mIsChecked(false)
	, mGoal(pos)
	, mChangeGoalSecond(0)
{
}


void Kokoha::GameGoalKey::update()
{
	if (mIsChecked) { return; }

	mChangeGoalSecond -= Scene::DeltaTime();

	if (mChangeGoalSecond < 0)
	{
		changeGoal();
		mChangeGoalSecond = Random(CHANGE_GOAL_SECOND.first, CHANGE_GOAL_SECOND.second);
	}

	walkToGoal(SPEED, mGoal);
}


void Kokoha::GameGoalKey::draw() const
{
	const Point pos(mIsChecked ? TEXTURE_SIZE.x : 0, 0);
	TextureAsset(U"GoalKey")(pos, TEXTURE_SIZE).drawAt(mBody.center);
}


void Kokoha::GameGoalKey::checkAnother(const GameObject& another)
{
	if (checkTypeAndCollision(another, ObjectType::PLAYER))
	{
		mIsChecked = true;
	}
}


void Kokoha::GameGoalKey::changeGoal()
{
	double minDistance = Inf<double>;
	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	for (int32 i = 0; i < RANDOM_POS_NUM; ++i)
	{
		Vec2 goal = StageData::integerToPixel(Random(0, StageData::N - 1));

		if (!GameManager::instance().getStageData().isWalkAble(goal)) { continue; }

		// 評価値
		double distance
			= GameManager::instance().getStageData().getDistance(goal, mBody.center)
			- 1.1*GameManager::instance().getStageData().getDistance(goal, playerPos);

		if (distance > minDistance) { continue; }
		
		distance = minDistance;
		mGoal = goal;
	}
}
