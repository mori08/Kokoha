#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	MoveEvent�N���X
	EventObject��setLinearMove�֐����g����,
	�I�u�W�F�N�g���ړ������܂�
	*/
	class MoveEvent : public Event
	{
	private:

		// �I�u�W�F�N�g�̖��O
		String mName;

		// �ړ�����(�b)
		double mTimeSecond;

		// �ړ���
		Point mMovement;

		// �C�x���g�S�̂�҂����邩
		bool mWait;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() const override;

		bool isCompleted() const override;

	};
}