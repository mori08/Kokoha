#include "DefenceEnemy.h"
#include "../../GameManager.h"


namespace 
{
	// ゴールを守る速さ
	constexpr double DEFENCE_SPEED = 1.0;

	// プレイヤーを追いかける速さ
	constexpr double CHASE_SPEED = 1.5;

	// プレイヤーを追いかける距離
	constexpr int32 CHASE_DISTANCE = 5;
}


Kokoha::DefenceEnemy::DefenceEnemy(const Vec2& pos)
	: BlackEnemy(pos)
	, mDefenceMode(true)
	, mToPos(pos)
	, mGoalPos(pos)
{
}


void Kokoha::DefenceEnemy::update()
{
	BlackEnemy::update();

	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	if (!mDefenceMode)
	{
		attack();
		return;
	}

	if (mGoalPos.distanceFrom(playerPos) < CHASE_DISTANCE * StageData::SQUARE_SIZE
		&& GameManager::instance().getStageData().getDistance(mGoalPos, playerPos) < CHASE_DISTANCE)
	{
		walkToGoal(CHASE_SPEED, playerPos);
		return;
	}

	walkToGoal(DEFENCE_SPEED, mToPos);
}


void Kokoha::DefenceEnemy::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoalPos = pos.value();
	}
}
