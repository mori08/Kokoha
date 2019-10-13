#include "EventScene.h"
#include "../EventManager.h"


Kokoha::EventScene::EventScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::EventScene::update()
{
	EventManager::instance().update();
}


void Kokoha::EventScene::draw() const
{
	EventManager::instance().draw();
}
