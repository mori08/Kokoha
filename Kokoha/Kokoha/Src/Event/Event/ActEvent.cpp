#include "ActEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 2;

	// �C���f�b�N�X
	constexpr size_t OBJ_NAME = 0; // �I�u�W�F�N�g��
	constexpr size_t ACT_NAME = 1; // ���o��
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
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ���o�����݂��܂���.");
		EventManager::instance().addErrorMessage(U"�I�u�W�F�N�g�� > " + mObjName);
		EventManager::instance().addErrorMessage(U"���o�� > " + mActName);
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
