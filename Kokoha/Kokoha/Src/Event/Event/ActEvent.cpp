#include "ActEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 2;

	// インデックス
	constexpr size_t OBJ_NAME = 0; // オブジェクト名
	constexpr size_t ACT_NAME = 1; // 演出名
}


bool Kokoha::ActEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mObjName = eventArg[OBJ_NAME];
	if (!isExistedObject(mObjName)) { return false; }

	mActName = eventArg[ACT_NAME];
	if (!EventManager::instance().getObjectPtr(mObjName)->isExistedAct(mActName))
	{
		EventManager::instance().addErrorMessage(U"[ActEvent::load]");
		EventManager::instance().addErrorMessage(U"指定された演出が存在しません.");
		EventManager::instance().addErrorMessage(U"オブジェクト名 > " + mObjName);
		EventManager::instance().addErrorMessage(U"演出名 > " + mActName);
		return false;
	}

	return true;
}


void Kokoha::ActEvent::perform()
{
	EventManager::instance().getObjectPtr(mObjName)->act(mActName);
}


bool Kokoha::ActEvent::isCompleted() const
{
	return EventManager::instance().getObjectPtr(mObjName)->isFinished();
}
