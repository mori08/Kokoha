#include "AdventureScene.h"
#include "../AdventureManager.h"


Kokoha::AdventureScene::AdventureScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::AdventureScene::update()
{
	AdventureManager::instance().update();
}


void Kokoha::AdventureScene::draw() const
{
	AdventureManager::instance().draw();
}
