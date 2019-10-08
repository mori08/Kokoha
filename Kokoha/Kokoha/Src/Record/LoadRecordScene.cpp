#include "LoadRecordScene.h"
#include "RecordManager.h"


Kokoha::LoadRecordScene::LoadRecordScene(const InitData& init)
	: LoadScene(init)
{
}


void Kokoha::LoadRecordScene::load()
{
	RecordManager::instatnce().load();
}


void Kokoha::LoadRecordScene::complete()
{
	changeScene(SceneName::TITLE);
}
