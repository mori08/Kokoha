#include "SaveRecordScene.h"
#include "RecordManager.h"


Kokoha::SaveRecordScene::SaveRecordScene(const InitData& init)
	: LoadScene(init, U"Saving")
{
}


void Kokoha::SaveRecordScene::load()
{
	RecordManager::instatnce().save();
}


void Kokoha::SaveRecordScene::complete()
{
	changeScene(SceneName::TITLE);
}
