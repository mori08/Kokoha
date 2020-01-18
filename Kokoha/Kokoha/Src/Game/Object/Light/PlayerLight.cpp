#include "PlayerLight.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 10.0;
}


Kokoha::PlayerLight::PlayerLight(double radius)
	: GameLight(Circle(GameManager::instance().getPlayerPos(), radius* StageData::SQUARE_SIZE), SPEED)
{

}


void Kokoha::PlayerLight::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::PLAYER))
	{
		mGoal = pos.value();
	}
}
