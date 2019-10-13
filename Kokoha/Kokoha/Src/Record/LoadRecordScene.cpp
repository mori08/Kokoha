#include "LoadRecordScene.h"
#include "RecordManager.h"


Kokoha::LoadRecordScene::LoadRecordScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadRecordScene::load()
{
	RecordManager::instatnce().load();
	return none;
}


SceneName Kokoha::LoadRecordScene::complete()
{
	return SceneName::TITLE;
}
