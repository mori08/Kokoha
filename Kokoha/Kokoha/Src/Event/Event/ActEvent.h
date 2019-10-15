#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	ActEvent�N���X
	�I�u�W�F�N�g�̉��o�̎��s
	*/
	class ActEvent : public Event
	{
	private:

		// �I�u�W�F�N�g��
		String mObjName;

		// ���o��
		String mActName;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}