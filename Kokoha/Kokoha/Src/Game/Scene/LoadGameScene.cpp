#include "LoadGameScene.h"
#include "../GameManager.h"


Kokoha::LoadGameScene::LoadGameScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadGameScene::load()
{
	if (auto errorMessage = GameManager::instance().load(U"1-1"))
	{
		mIsSuccess = false;
		return errorMessage.value();
	}

	mIsSuccess = true;
	return none;
}


SceneName Kokoha::LoadGameScene::complete()
{
	return mIsSuccess ? SceneName::GAME : SceneName::TITLE;
}
