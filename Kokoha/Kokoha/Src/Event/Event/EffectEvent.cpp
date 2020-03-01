#include "EffectEvent.h"
#include "../EventManager.h"


namespace
{
	// �����T�C�Y
	constexpr size_t ARG_SIZE = 1;

	// �C���f�b�N�X
	constexpr size_t NAME = 0; // ���O
}


bool Kokoha::EffectEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mEffectName = eventArg[NAME];
	if (mEffectName == U"Dark" || mEffectName == U"Noise")
	{
		return true;
	}

	EventManager::instance().addErrorMessage(U"[EffectEvent::load]");
	EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�G�t�F�N�g�����݂��܂���");
	EventManager::instance().addErrorMessage(U"�G�t�F�N�g�� > " + mEffectName);
	return false;
}


void Kokoha::EffectEvent::perform()
{
	EventManager::instance().setEffect(mEffectName);
}


bool Kokoha::EffectEvent::isCompleted() const
{
	return true;
}
