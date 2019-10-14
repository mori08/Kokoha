#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	WaitEvent�N���X
	�w�肵���b���C�x���g�S�̂�ҋ@
	*/
	class WaitEvent : public Event
	{
	private:

		// �I������(�b) (load�őҋ@����,perform�ŊJ�n���Ԃ����Z)
		double mTimeSecond;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}