#include "LoadEventScene.h"
#include "../EventManager.h"


Kokoha::LoadEventScene::LoadEventScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadEventScene::load()
{
	EventManager::instance().init();
	if (mIsScuccess = EventManager::instance().load(U"Assets/Data/Event/TestEvent.csv"))
	{
		return none;
	}

	return EventManager::instance().getErrorMessage();
}


SceneName Kokoha::LoadEventScene::complete()
{
	if (mIsScuccess)
	{
		return SceneName::TITLE;
	}

	return SceneName::TITLE;
}
