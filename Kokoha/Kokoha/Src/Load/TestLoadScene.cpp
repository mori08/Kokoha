#include "TestLoadScene.h"
#include "../Record/RecordManager.h"
#include "../Game/GameManager.h"
#include "../Event/EventManager.h"
#include "../Adventure/AdventureManager.h"


Kokoha::ErrorMessage Kokoha::TestLoadScene::load()
{
	// ���R�[�h
	RecordManager::instance().load();

	// �Q�[��
	GameManager::instance().setName(U"1-1");
	GameManager::instance().load();
	
	// ���[�h
	EventManager::instance().setEventFileName(U"1-1");
	EventManager::instance().load();

	// �A�h�x���`���[
	AdventureManager::instance().setAreaId(0);
	AdventureManager::instance().load();
	
	return none;
}


SceneName Kokoha::TestLoadScene::complete()
{
	return SceneName::TITLE;
}
