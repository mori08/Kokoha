#include "DefenceChaseEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.8;
}


Kokoha::DefenceChaseEnemy::DefenceChaseEnemy(const Vec2& pos)
	: DefenceEnemy(pos)
{
}


void Kokoha::DefenceChaseEnemy::attack()
{
	walkToGoal(SPEED, GameManager::instance().getPlayerPos());
}
