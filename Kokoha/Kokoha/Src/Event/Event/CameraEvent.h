#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	CameraEventƒNƒ‰ƒX
	ƒJƒƒ‰‚ÌˆÚ“®
	*/
	class CameraEvent : public Event
	{
	private:

		// ˆÚ“®ŠÔ(•b)
		double mTimeSecond;

		// ˆÚ“®—Ê
		Point mMovement;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}