#include "MoveEvent.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 4;

	// インデックス
	constexpr size_t NAME = 0;
	constexpr size_t X    = 1;
	constexpr size_t Y    = 2;
	constexpr size_t WAIT = 3;
}


bool Kokoha::MoveEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mName = eventArg[NAME];
	if (!isExistedObject(mName)) { return false; }



	return true;
}


void Kokoha::MoveEvent::perform() const
{
}


bool Kokoha::MoveEvent::isCompleted() const
{
	return false;
}
