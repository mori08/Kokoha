#include "LoadRecordScene.h"
#include "RecordManager.h"
#include "../Adventure/AdventureManager.h"
#include "../Cassette/CassetteManager.h"


Kokoha::LoadRecordScene::LoadRecordScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadRecordScene::load()
{
	// ƒŒƒR[ƒh‚Ì“Ç‚İ‚İ
	mLoadResult = RecordManager::instance().load();

	// Adventure ‚Ìİ’è
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	// Cassette ‚Ìİ’è
	CassetteManager::instance().load();

	return none;
}


SceneName Kokoha::LoadRecordScene::complete()
{
	switch (mLoadResult)
	{
	case RecordManager::LoadResult::NEW_GAME:
		return SceneName::TITLE;

	case RecordManager::LoadResult::CONTINUE:
		return SceneName::ADVENTURE;

	case RecordManager::LoadResult::ERROR:
		return SceneName::TITLE;
	}
	return SceneName::TITLE;
}
