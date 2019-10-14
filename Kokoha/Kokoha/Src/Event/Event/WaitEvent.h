#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	WaitEventクラス
	指定した秒数イベント全体を待機
	*/
	class WaitEvent : public Event
	{
	private:

		// 終了時間(秒) (loadで待機時間,performで開始時間を加算)
		double mTimeSecond;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}