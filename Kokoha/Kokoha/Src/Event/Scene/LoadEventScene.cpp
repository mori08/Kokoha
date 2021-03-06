#include "LoadEventScene.h"
#include "../EventManager.h"


Kokoha::LoadEventScene::LoadEventScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadEventScene::load()
{
	EventManager::instance().init();
	if (mIsScuccess = EventManager::instance().load())
	{
		return none;
	}

	return EventManager::instance().getErrorMessage();
}


SceneName Kokoha::LoadEventScene::complete()
{
	if (mIsScuccess)
	{
		return SceneName::EVENT;
	}

	return SceneName::TITLE;
}
