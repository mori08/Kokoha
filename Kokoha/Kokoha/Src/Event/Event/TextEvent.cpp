#include "TextEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 4;

	// �C���f�b�N�X
	constexpr size_t SPEAKER = 0; // �b����̖��O
	constexpr size_t ICON    = 1; // �A�C�R��
	constexpr size_t SPAN    = 2; // �ꕶ����\�����鎞��
	constexpr size_t TEXT    = 3; // �e�L�X�g
}


bool Kokoha::TextEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mSpeakerName = eventArg[SPEAKER];
	mIconName    = eventArg[ICON];

	if (!toDouble(mSpanSecond, eventArg[SPAN])) { return false; }

	mText = eventArg[TEXT];

	return true;
}


void Kokoha::TextEvent::perform()
{
	EventManager::instance().getTextBox().set(mSpeakerName, mIconName, mSpanSecond, mText);
}


bool Kokoha::TextEvent::isCompleted() const
{
	return EventManager::instance().getTextBox().isReady();
}
