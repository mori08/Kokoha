#include "BackgroundEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 1;

	// �C���f�b�N�X
	constexpr size_t BACKGROUND_NAME = 0; // �w�i�摜�̖��O
}


bool Kokoha::BackgroundEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mBackgroundName = eventArg[BACKGROUND_NAME];

	return true;
}


void Kokoha::BackgroundEvent::perform()
{
	EventManager::instance().setBackground(mBackgroundName);
}


bool Kokoha::BackgroundEvent::isCompleted() const
{
	return true;
}
