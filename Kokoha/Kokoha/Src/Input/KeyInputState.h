#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	KeyInputState�N���X
	MouseInputState�N���X
	�L�[�{�[�h�ł̓��͂��s�����
	*/
	class KeyInputState : public InputState
	{
	public:

		bool decesion() const override;

		bool cancel() const override;

		Optional<String> selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap&) const override;
	};
}