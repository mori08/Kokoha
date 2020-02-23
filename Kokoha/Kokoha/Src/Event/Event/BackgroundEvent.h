#pragma once


#include "Event.h"

namespace Kokoha
{
	class BackgroundEvent : public Event
	{
	private:

		// �w�i�摜�̖��O
		String mBackgroundName;

		// �����J�������W
		Point mInitCameraPos;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}