#include "MoveEvent.h"
#include "../EventManager.h"


namespace
{
	// �����̃T�C�Y
	constexpr size_t ARG_SIZE = 4;

	// �C���f�b�N�X
	constexpr size_t NAME     = 0; // �I�u�W�F�N�g�̖��O
	constexpr size_t TIME     = 1; // �ړ�����
	constexpr size_t MOVEMENT = 2; // �ړ���
	constexpr size_t WAIT     = 3; // �҂�
}


bool Kokoha::MoveEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mName = eventArg[NAME];
	if (!isExistedObject(mName)) { return false; }

	if (!toDouble(mTimeSecond, eventArg[TIME])) { return false; }

	if (!toPoint(mMovement, eventArg[MOVEMENT])) { return false; }

	if (!toBool(mWait, eventArg[WAIT])) { return false; }

	return true;
}


void Kokoha::MoveEvent::perform()
{
	EventManager::instance().getObjectPtr(mName)->setLinearMove(mTimeSecond, mMovement, mWait);
}


bool Kokoha::MoveEvent::isCompleted() const
{
	return EventManager::instance().getObjectPtr(mName)->isFinished();
}
