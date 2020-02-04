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
	// ���R�[�h�̓ǂݍ���
	RecordManager::instance().load();

	// Adventure �̐ݒ�
	AdventureManager::instance().setAreaId(RecordManager::instance().getRecord(U"AreaId"));
	AdventureManager::instance().load();
	AdventureManager::instance().setPlayerFromRecord();

	// Cassette �̐ݒ�
	CassetteManager::instance().load();

	return none;
}


SceneName Kokoha::LoadRecordScene::complete()
{
	return SceneName::ADVENTURE;
}
