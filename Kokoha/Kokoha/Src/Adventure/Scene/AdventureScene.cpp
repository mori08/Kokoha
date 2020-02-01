#include "AdventureScene.h"
#include "../AdventureManager.h"
#include "../../Game/GameManager.h"


Kokoha::AdventureScene::AdventureScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::AdventureScene::update()
{
	AdventureManager::instance().update();

	if (auto sceneName = AdventureManager::instance().getSceneName())
	{
		changeScene(sceneName.value());
	}
}


void Kokoha::AdventureScene::draw() const
{
	AdventureManager::instance().draw();
}
