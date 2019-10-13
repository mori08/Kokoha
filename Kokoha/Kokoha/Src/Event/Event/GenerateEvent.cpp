#include "GenerateEvent.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"

// �C�x���g�I�u�W�F�N�g
#include "../Object/TestEventObject.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 4;

	// �C���f�b�N�X
	constexpr size_t TYPE = 0; // �I�u�W�F�N�g�̎��
	constexpr size_t NAME = 1; // �I�u�W�F�N�g�̖��O
	constexpr size_t X    = 2; // X���W
	constexpr size_t Y    = 3; // Y���W
}


std::unordered_map<String, Kokoha::GenerateEventObjectFunc> Kokoha::GenerateEvent::sGenerateObjectMap;


bool Kokoha::GenerateEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mType = eventArg[TYPE];
	if (!sGenerateObjectMap.count(mType))
	{
		EventManager::instance().addErrorMessage(U"[Generate::Event]");
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�I�u�W�F�N�g�̌^���o�^����Ă܂���.");
		EventManager::instance().addErrorMessage(U"�^�� > " + mType);
		return false;
	}

	mName = eventArg[NAME];

	if (!toInteger(mPos.x, eventArg[X]) || !toInteger(mPos.y, eventArg[Y])) { return false; }

	return true;
}


void Kokoha::GenerateEvent::perform() const
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
