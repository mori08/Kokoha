#include "DefenceGuardEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.6;
}


Kokoha::DefenceGuardEnemy::DefenceGuardEnemy(const Vec2& pos)
	: DefenceEnemy(pos)
{
}


void Kokoha::DefenceGuardEnemy::attack()
{
	const Vec2 playerPos = GameManager::instance().getPlayerPos();
	walkToGoal(SPEED, (mGoalPos + playerPos) / 2);
}
