#include "GameScene.h"
#include "../GameManager.h"


Kokoha::GameScene::GameScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::GameScene::update()
{
	GameManager::instance().getState()->update();
}


void Kokoha::GameScene::draw() const
{
	GameManager::instance().getState()->draw();
}
