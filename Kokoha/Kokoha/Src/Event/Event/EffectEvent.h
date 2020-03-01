#pragma once


#include "Event.h"


namespace Kokoha
{
	/*
	EffectEvent�N���X
	�Ó]��m�C�Y�̃C�x���g
	*/
	class EffectEvent : public Event
	{
	private:

		// �G�t�F�N�g��
		String mEffectName;

	public:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}