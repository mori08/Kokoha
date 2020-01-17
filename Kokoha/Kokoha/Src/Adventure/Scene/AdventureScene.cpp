#include "AdventureScene.h"
#include "../AdventureManager.h"


Kokoha::AdventureScene::AdventureScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::AdventureScene::update()
{
	if (Key0.down())
	{
		changeScene(SceneName::LOAD_GAME);
	}

	AdventureManager::instance().update();
}


void Kokoha::AdventureScene::draw() const
{
	AdventureManager::instance().draw();
}
