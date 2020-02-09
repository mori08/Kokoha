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

		bool decesion() const override
		{
			return MouseL.up() && Scene::Rect().mouseOver();
		}

		bool cancel() const override
		{
			return MouseR.up() && Scene::Rect().mouseOver();
		}

		Optional<String> selectButton(ButtonPtr& selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const override;

	};
}