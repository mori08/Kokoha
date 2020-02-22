#include "ChangeSceneEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 1;

	// インデックス
	constexpr size_t SCENE_NAME = 0; // シーン名
}


std::unordered_map<String, SceneName> Kokoha::ChangeSceneEvent::sSceneNameMap;


bool Kokoha::ChangeSceneEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	if (!sSceneNameMap.count(eventArg[SCENE_NAME]))
	{
		EventManager::instance().addErrorMessage(U"[ChangeSceneEvent::load]");
		EventManager::instance().addErrorMessage(U"指定されたシーンが登録されていません.");
		EventManager::instance().addErrorMessage(U"setSceneNameMap関数を確認してください.");
		EventManager::instance().addErrorMessage(U"演習名 > " + eventArg[SCENE_NAME]);
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
