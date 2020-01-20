#include "GoalLight.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	const double SPEED = 2.0;
}


Kokoha::GoalLight::GoalLight(double radius, double eraseSecond, bool isRooting)
	: GameLight(Circle(GameManager::instance().getPlayerPos(),radius*StageData::SQUARE_SIZE), SPEED, eraseSecond)
	, mIsRooting(isRooting)
{
	
}


void Kokoha::GoalLight::update()
{
	GameLight::update();
}


void Kokoha::GoalLight::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoal        = pos.value();
		mBody.center = pos.value();
	}
}
