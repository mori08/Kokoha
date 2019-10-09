#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	EmptyEvent�N���X
	��̃C�x���g
	�L���[�̍ŏ��ɓ���Ă���
	*/
	class EmptyEvent : public Event
	{
	public:

		bool load(const EventArg&) override
		{
			return true;
		}

		void perform()const override
		{
		}

		bool isCompleted()const override
		{
			return true;
		}

	};
}