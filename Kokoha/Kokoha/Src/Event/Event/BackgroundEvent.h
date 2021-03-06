#pragma once


#include "Event.h"

namespace Kokoha
{
	class BackgroundEvent : public Event
	{
	private:

		// 背景画像の名前
		String mBackgroundName;

		// 初期カメラ座標
		Point mInitCameraPos;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}