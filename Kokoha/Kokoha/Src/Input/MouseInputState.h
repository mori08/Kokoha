#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	MouseInputState�N���X
	�}�E�X�ł̓��͂��s�����
	*/
	class MouseInputState : public InputState
	{
	private:

		bool decesion() const override;

		bool cancel() const override;

		Optional<String> selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const;

	};
}