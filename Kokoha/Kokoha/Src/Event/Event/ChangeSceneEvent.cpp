#include "ChangeSceneEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 1;

	// �C���f�b�N�X
	constexpr size_t SCENE_NAME = 0; // �V�[����
}


std::unordered_map<String, SceneName> Kokoha::ChangeSceneEvent::sSceneNameMap;


bool Kokoha::ChangeSceneEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	if (!sSceneNameMap.count(eventArg[SCENE_NAME]))
	{
		EventManager::instance().addErrorMessage(U"[ChangeSceneEvent::load]");
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�V�[�����o�^����Ă��܂���.");
		EventManager::instance().addErrorMessage(U"setSceneNameMap�֐����m�F���Ă�������.");
		EventManager::instance().addErrorMessage(U"���K�� > " + eventArg[SCENE_NAME]);
		return false;
	}

	mSceneName = sSceneNameMap[eventArg[SCENE_NAME]];

	return true;
}


void Kokoha::ChangeSceneEvent::perform()
{
	EventManager::instance().setSceneName(mSceneName);
}


bool Kokoha::ChangeSceneEvent::isCompleted() const
{
	return true;
}


void Kokoha::ChangeSceneEvent::setSceneNameMap()
{
	sSceneNameMap[U"LoadAdventure"] = SceneName::LOAD_ADVENTURE;
	sSceneNameMap[U"Adventure"]     = SceneName::ADVENTURE;
}
