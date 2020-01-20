#include "RootingLight.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 4.0;

	// ”¼Œa
	constexpr double RADIUS = 0.5;
}


Kokoha::RootingLight::RootingLight(double eraseSecond)
	: GameLight(Circle(GameManager::instance().getPlayerPos(), RADIUS*StageData::SQUARE_SIZE), SPEED, eraseSecond)
{
}


void Kokoha::RootingLight::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoal = pos.value();
	}

	if (checkTypeAndCollision(another, ObjectType::GOAL))
	{
		mEraseAble = true;
	}
}
