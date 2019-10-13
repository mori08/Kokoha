#include "LoadEventScene.h"
#include "../EventManager.h"


Kokoha::LoadEventScene::LoadEventScene(const InitData& init)
	: LoadScene(init)
{
}


void Kokoha::LoadEventScene::load()
{
	EventManager::instance().init();
	mIsScuccess = EventManager::instance().load(U"Assets/Data/Event/TestEvent.csv");
}


void Kokoha::LoadEventScene::complete()
{
	if (mIsScuccess)
	{
		changeScene(SceneName::TITLE);
	}
	else
	{
		changeScene(SceneName::TITLE);
	}
}
