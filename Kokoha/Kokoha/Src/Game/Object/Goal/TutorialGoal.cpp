#include "TutorialGoal.h"
#include "../../GameManager.h"
#include "../../State/Tutorial/AwakeState.h"


Kokoha::TutorialGoal::TutorialGoal(const Vec2& pos)
	: GameGoal(pos)
{
}


void Kokoha::TutorialGoal::checkAnother(const GameObject& another)
{
	if (checkTypeAndCollision(another, ObjectType::PLAYER))
	{
		GameManager::instance().setState(std::make_unique<AwakeState>());
	}
}
