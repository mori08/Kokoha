#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	CameraEventクラス
	カメラの移動
	*/
	class CameraEvent : public Event
	{
	private:

		// 移動時間(秒)
		double mTimeSecond;

		// 移動量
		Point mMovement;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}