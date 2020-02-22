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

	// Adventure �̐ݒ�
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	// Cassette �̐ݒ�
	CassetteManager::instance().load();

	// Game ��Tutorial�ɐݒ�
	GameManager::instance().setName(U"Tutorial");

	return none;
}


SceneName Kokoha::LoadNewGameScene::complete()
{
	return SceneName::LOAD_GAME;
}
