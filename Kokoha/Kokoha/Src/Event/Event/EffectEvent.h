#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	EffectEventクラス
	暗転やノイズのイベント
	*/
	class EffectEvent : public Event
	{
	private:

		// エフェクト名
		String mEffectName;

	public:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}