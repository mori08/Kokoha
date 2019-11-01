#include "ChaseEnemyAttack.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.5;
}


Kokoha::ChaseEnemyAttack::ChaseEnemyAttack(const Vec2& pos)
	: GameAttack(pos, SPEED)
	, mMinDistance(Inf<double>)
{
}


void Kokoha::ChaseEnemyAttack::update()
{
	GameAttack::update();

	mMinDistance = Inf<double>;
	mGoal        = mBody.center;
}


void Kokoha::ChaseEnemyAttack::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::WHITE_ENEMY))
	{
		const double distance = (pos.value() - mBody.center).length();
		if (distance < mMinDistance)
		{
			mMinDistance = distance;
			mGoal        = pos.value();
		}
	}
}
