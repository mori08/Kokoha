#include "LoadAdventureScene.h"
#include "../AdventureManager.h"


Kokoha::LoadAdventureScene::LoadAdventureScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadAdventureScene::load()
{
	if (auto errorMessage = AdventureManager::instance().load(U"Assets/Data/Adventure/DoctorRoom.csv"))
	{
		mIsSuccess = false;
		return errorMessage.value();
	}

	mIsSuccess = true;
	return none;
}


SceneName Kokoha::LoadAdventureScene::complete()
{
	return mIsSuccess ? SceneName::ADVENTURE : SceneName::TITLE;
}
