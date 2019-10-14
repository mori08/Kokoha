#include "MoveEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 4;

	// インデックス
	constexpr size_t NAME     = 0; // オブジェクトの名前
	constexpr size_t TIME     = 1; // 移動時間
	constexpr size_t MOVEMENT = 2; // 移動量
	constexpr size_t WAIT     = 3; // 待ち
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
