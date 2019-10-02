#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	MouseInputStateクラス
	マウスでの入力を行う状態
	*/
	class MouseInputState : public InputState
	{
	private:

		bool decesion() const override;

		bool cancel() const override;

		Optional<String> selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const;

	};
}