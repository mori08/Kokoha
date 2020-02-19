#include "CameraEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 2;

	// インデックス
	constexpr size_t TIME     = 0; // 移動時間
	constexpr size_t MOVEMENT = 1; // 移動量
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
