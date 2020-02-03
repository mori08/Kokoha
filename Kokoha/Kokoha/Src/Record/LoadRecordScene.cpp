#include "LoadRecordScene.h"
#include "RecordManager.h"
#include "../Adventure/AdventureManager.h"


Kokoha::LoadRecordScene::LoadRecordScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadRecordScene::load()
{
	RecordManager::instance().load();
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	return none;
}


SceneName Kokoha::LoadRecordScene::complete()
{
	return SceneName::ADVENTURE;
}
