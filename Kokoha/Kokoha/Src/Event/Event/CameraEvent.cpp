#include "CameraEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 2;

	// �C���f�b�N�X
	constexpr size_t TIME     = 0; // �ړ�����
	constexpr size_t MOVEMENT = 1; // �ړ���
}


bool Kokoha::CameraEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	if (!toDouble(mTimeSecond, eventArg[TIME]))   { return false; }

	if (!toPoint(mMovement, eventArg[MOVEMENT]))  { return false; }

	return true;
}


void Kokoha::CameraEvent::perform()
{
	EventManager::instance().setCameraMove(mTimeSecond, mMovement);
}


bool Kokoha::CameraEvent::isCompleted() const
{
	return true;
}
