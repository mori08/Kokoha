#include "EventScene.h"
#include "../EventManager.h"


Kokoha::EventScene::EventScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::EventScene::update()
{
	EventManager::instance().update();

#ifdef _DEBUG
	if (Key0.up())
	{
		changeScene(SceneName::LOAD_EVENT);
		return;
	}
#endif // _DEBUG

	if (auto sceneName = EventManager::instance().getSceneName())
	{
		changeScene(sceneName.value());
	}
}


void Kokoha::EventScene::draw() const
{
	EventManager::instance().draw();
}
