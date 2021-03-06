#include "TutorialCassetteState.h"
#include "TutorialGoalState.h"
#include "../../GameManager.h"
#include "../../../Input/InputManager.h"
#include "../../../Cassette/CassetteManager.h"


namespace
{
	// ΪWρ
	constexpr int32 ACHIEVE_COUNT = 4;

	// υIDΜ`ζΚu
	constexpr Point EQUIPMENT_POS(15, 200);
}


Kokoha::TutorialCassetteState::TutorialCassetteState()
	: TutorialState(U"υΜΟX", U"EnterL[")
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


void Kokoha::TutorialCassetteState::draw() const
{
	TutorialState::draw();

	if (mEquipmentChangeCount % 2)
	{
		FontAsset(U"20")(U"υa").draw(EQUIPMENT_POS);
	}
	else
	{
		FontAsset(U"20")(U"υ`").draw(EQUIPMENT_POS);
	}
}
