#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	MoveEventクラス
	EventObjectのsetLinearMove関数を使って,
	オブジェクトを移動させます
	*/
	class MoveEvent : public Event
	{
	private:

		// オブジェクトの名前
		String mName;

		// 移動時間(秒)
		double mTimeSecond;

		// 移動量
		Point mMovement;

		// イベント全体を待たせるか
		bool mWait;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() const override;

		bool isCompleted() const override;

	};
}