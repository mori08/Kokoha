#include "AdventureScene.h"
#include "../AdventureManager.h"
#include "../Window/TutorialWindow.h"
#include "../../Game/GameManager.h"
#include "../../Record/RecordManager.h"


Kokoha::AdventureScene::AdventureScene(const InitData& init)
	: IScene(init)
{
	AdventureManager::instance().setSceneName(none);
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
