#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	CameraEvent�N���X
	�J�����̈ړ�
	*/
	class CameraEvent : public Event
	{
	private:

		// �ړ�����(�b)
		double mTimeSecond;

		// �ړ���
		Point mMovement;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}