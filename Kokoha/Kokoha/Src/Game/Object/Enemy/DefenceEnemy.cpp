#include "DefenceEnemy.h"
#include "../../GameManager.h"


namespace 
{
	// �S�[������鑬��
	constexpr double DEFENCE_SPEED = 1.0;

	// �v���C���[��ǂ������鑬��
	constexpr double CHASE_SPEED = 1.5;

	// �v���C���[��ǂ������鋗��
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
