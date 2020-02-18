#include "ReloadGameScene.h"
#include "../GameManager.h"


Kokoha::ReloadGameScene::ReloadGameScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::ReloadGameScene::load()
{
	if (auto errorMessage = GameManager::instance().reload())
	{
		mIsSuccess = false;
		return errorMessage.value();
	}

	mIsSuccess = true;
	return none;
}


SceneName Kokoha::ReloadGameScene::complete()
{
	return mIsSuccess ? SceneName::GAME : SceneName::TITLE;
}
