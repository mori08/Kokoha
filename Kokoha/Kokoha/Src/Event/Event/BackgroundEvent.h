#pragma once


#include "Event.h"

namespace Kokoha
{
	class BackgroundEvent : public Event
	{
	private:

		// ”wŒi‰æ‘œ‚Ì–¼‘O
		String mBackgroundName;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}