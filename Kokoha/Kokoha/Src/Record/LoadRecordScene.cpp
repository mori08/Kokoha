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
	// レコードの読み込み
	mLoadResult = RecordManager::instance().load();

	// Adventure の設定
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	// Cassette の設定
	CassetteManager::instance().load();

	return none;
}


SceneName Kokoha::LoadRecordScene::complete()
{
	switch (mLoadResult)
	{
	case RecordManager::LoadResult::NEW_GAME:
		return SceneName::LOAD_NEWGAME;

	case RecordManager::LoadResult::CONTINUE:
		return SceneName::ADVENTURE;

	case RecordManager::LoadResult::ERROR:
		return SceneName::TITLE;
	}
	return SceneName::TITLE;
}
