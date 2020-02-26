#include "TutorialCassetteState.h"
#include "TutorialGoalState.h"
#include "../../GameManager.h"
#include "../../../Input/InputManager.h"


namespace
{
	// �ڕW��
	constexpr int32 ACHIEVE_COUNT = 4;
}


Kokoha::TutorialCassetteState::TutorialCassetteState()
	: TutorialState(U"�����̕ύX", U"Enter�L�[")
	, mEquipmentChangeCount(0)
{
}


void Kokoha::TutorialCassetteState::update()
{
	GameManager::instance().update();

	if (InputManager::instance().decision())
	{
		++mEquipmentChangeCount;
	}

	if (mEquipmentChangeCount > ACHIEVE_COUNT)
	{
		GameManager::instance().setState(std::make_unique<TutorialGoalState>());
		return;
	}

	updateAchieveRate(1.0 * mEquipmentChangeCount / ACHIEVE_COUNT);

	TutorialState::update();
}
