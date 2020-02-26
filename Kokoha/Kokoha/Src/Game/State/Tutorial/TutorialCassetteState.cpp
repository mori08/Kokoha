#include "TutorialCassetteState.h"
#include "TutorialGoalState.h"
#include "../../GameManager.h"
#include "../../../Input/InputManager.h"


namespace
{
	// 目標回数
	constexpr int32 ACHIEVE_COUNT = 4;
}


Kokoha::TutorialCassetteState::TutorialCassetteState()
	: TutorialState(U"装備の変更", U"Enterキー")
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
