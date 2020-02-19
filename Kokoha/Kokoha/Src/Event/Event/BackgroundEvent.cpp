#include "BackgroundEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 2;

	// �C���f�b�N�X
	constexpr size_t BACKGROUND_NAME = 0; // �w�i�摜�̖��O
	constexpr size_t INIT_CAMERA_POS = 1; // �J�����̏������W
}


bool Kokoha::BackgroundEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mBackgroundName = eventArg[BACKGROUND_NAME];

	if (!toPoint(mInitCameraPos, eventArg[INIT_CAMERA_POS])) { return false; }

	return true;
}


void Kokoha::BackgroundEvent::perform()
{
	EventManager::instance().setBackground(mBackgroundName);
	EventManager::instance().setCameraPos(mInitCameraPos);
}


bool Kokoha::BackgroundEvent::isCompleted() const
{
	return true;
}
