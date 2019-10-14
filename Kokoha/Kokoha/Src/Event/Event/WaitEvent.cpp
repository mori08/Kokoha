#include "WaitEvent.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 1;

	// インデックス
	constexpr size_t TIME = 0; // 待機時間
}


bool Kokoha::WaitEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	if (!toDouble(mTimeSecond, eventArg[TIME])) { return false; }

	return true;
}


void Kokoha::WaitEvent::perform()
{
	mTimeSecond += Scene::Time();
}


bool Kokoha::WaitEvent::isCompleted() const
{
	return Scene::Time() > mTimeSecond;
}
