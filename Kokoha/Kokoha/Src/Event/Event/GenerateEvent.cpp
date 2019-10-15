#include "GenerateEvent.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"

// �C�x���g�I�u�W�F�N�g
#include "../Object/TestEventObject.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 3;

	// �C���f�b�N�X
	constexpr size_t TYPE = 0; // �I�u�W�F�N�g�̎��
	constexpr size_t NAME = 1; // �I�u�W�F�N�g�̖��O
	constexpr size_t POS  = 2; // �������W
}


std::unordered_map<String, Kokoha::GenerateEventObjectFunc> Kokoha::GenerateEvent::sGenerateObjectMap;


bool Kokoha::GenerateEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mType = eventArg[TYPE];
	if (!sGenerateObjectMap.count(mType))
	{
		EventManager::instance().addErrorMessage(U"[GenerateEvent::load]");
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�I�u�W�F�N�g�̌^���o�^����Ă܂���.");
		EventManager::instance().addErrorMessage(U"�^�� > " + mType);
		return false;
	}

	mName = eventArg[NAME];

	if (!toPoint(mPos,eventArg[POS])) { return false; }

	return true;
}


void Kokoha::GenerateEvent::perform()
{
	EventManager::instance().generateObject(mName, sGenerateObjectMap[mType](mPos));
}


bool Kokoha::GenerateEvent::isCompleted() const
{
	return true;
}


void Kokoha::GenerateEvent::setAllGenerateObjectFunc()
{
	setGenerateObjectFunc<TestEventObject>(U"Test");
}
