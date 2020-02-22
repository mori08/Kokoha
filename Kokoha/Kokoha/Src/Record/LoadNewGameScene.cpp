#include "LoadNewGameScene.h"
#include "RecordManager.h"
#include "../Game/GameManager.h"
#include "../Adventure/AdventureManager.h"
#include "../Cassette/CassetteManager.h"


Kokoha::LoadNewGameScene::LoadNewGameScene(const InitData& init)
	: LoadScene(init)
{
}


Kokoha::ErrorMessage Kokoha::LoadNewGameScene::load()
{
	RecordManager::instance().initAllRecord();

	// Adventure ‚Ìİ’è
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	// Cassette ‚Ìİ’è
	CassetteManager::instance().load();

	// Game ‚ğTutorial‚Éİ’è
	GameManager::instance().setName(U"Tutorial");

	return none;
}


SceneName Kokoha::LoadNewGameScene::complete()
{
	return SceneName::LOAD_GAME;
}
