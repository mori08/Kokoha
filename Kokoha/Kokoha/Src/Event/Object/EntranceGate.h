#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	EntranceGateクラス
	EventObject
	玄関ゲート
	*/
	class EntranceGate : public EventObject
	{
	public:

		EntranceGate(const Point& pos);

	};
}