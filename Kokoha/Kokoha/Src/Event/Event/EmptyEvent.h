#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	EmptyEventクラス
	空のイベント
	キューの最初に入れておく
	*/
	class EmptyEvent : public Event
	{
	public:

		bool load(const EventArg&) override
		{
			return true;
		}

		void perform()const override
		{
		}

		bool isCompleted()const override
		{
			return true;
		}

	};
}