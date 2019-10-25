#include "GameScene.h"
#include "../GameManager.h"


Kokoha::GameScene::GameScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::GameScene::update()
{
	GameManager::instance().update();
}


void Kokoha::GameScene::draw() const
{
	GameManager::instance().draw();
}
