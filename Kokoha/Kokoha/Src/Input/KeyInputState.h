#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	KeyInputStateクラス
	MouseInputStateクラス
	キーボードでの入力を行う状態
	*/
	class KeyInputState : public InputState
	{
	public:

		bool decesion() const override
		{
			return KeyEnter.up();
		}

		bool cancel() const override
		{
			return KeyBackspace.up();
		}

		Optional<String> selectButton(ButtonPtr& selectedButtonPtr, const ButtonPtrMap&) const override;
	};
}