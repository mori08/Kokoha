#include "EnemyLight.h"
#include "../../GameManager.h"


namespace
{
	// Œõ‚Ì”¼Œa
	constexpr double RADIUS = 32.0;
	// ‘¬‚³
	constexpr double SPEED = 2.0;
}


Kokoha::EnemyLight::EnemyLight(const Vec2& pos)
	: GameLight(Circle(pos, RADIUS), SPEED)
	, mPlayerPos(pos)
	, mMinDistance(Inf<double>)
{
}


void Kokoha::EnemyLight::update()
{
	GameLight::update();

	mMinDistance = Inf<double>;
}


void Kokoha::EnemyLight::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::PLAYER))
	{
		mPlayerPos = pos.value();
		return;
	}

	if (auto pos = another.checkTypeAndGetPos(ObjectType::BLACK_ENEMY))
	{
		const double distance = GameManager::instance().getStageData().getDistance(mPlayerPos, pos.value());
		if (distance < mMinDistance)
		{
			mMinDistance = distance;
			mGoal        = pos.value();
		}
		return;
	}

	if (auto pos = another.checkTypeAndGetPos(ObjectType::WHITE_ENEMY))
	{
		const double distance = GameManager::instance().getStageData().getDistance(mPlayerPos, pos.value());
		if (distance < mMinDistance)
		{
			mMinDistance = distance;
			mGoal        = pos.value();
		}
		return;
	}
}
