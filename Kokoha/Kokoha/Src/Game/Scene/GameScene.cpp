#include "GameScene.h"
#include "../GameManager.h"


Kokoha::GameScene::GameScene(const InitData& init)
	: IScene(init)
{
}


void Kokoha::GameScene::update()
{
	GameManager::instance().getState()->update();

	if (auto sceneName = GameManager::instance().getState()->isChangeAbleScene())
	{
		changeScene(sceneName.value());
	}
}


void Kokoha::GameScene::draw() const
{
	GameManager::instance().getState()->draw();
}
