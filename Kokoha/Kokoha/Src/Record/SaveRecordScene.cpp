#include "SaveRecordScene.h"
#include "RecordManager.h"


Kokoha::SaveRecordScene::SaveRecordScene(const InitData& init)
	: LoadScene(init, U"Saving")
{
}


Kokoha::ErrorMessage Kokoha::SaveRecordScene::load()
{
	RecordManager::instatnce().save();
	return none;
}


SceneName Kokoha::SaveRecordScene::complete()
{
	return SceneName::TITLE;
}
