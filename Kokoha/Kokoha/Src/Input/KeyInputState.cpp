#include "KeyInputState.h"
#include "../MyLibrary.h"


namespace
{
	// キーとボタンを動かす方向の配列
	const Array<std::pair<Key, Kokoha::Button::Direction>> KEY_DIRECTION
	{
		{KeyW, Kokoha::Button::Direction::UP    },
		{KeyS, Kokoha::Button::Direction::DOWN  },
		{KeyA, Kokoha::Button::Direction::LEFT  },
		{KeyD, Kokoha::Button::Direction::RIGHT }
	};
}


bool Kokoha::KeyInputState::decesion() const
{
	return KeyEnter.up;
}


bool Kokoha::KeyInputState::cancel() const
{
	return KeyBackspace.up;
}


Optional<String> Kokoha::KeyInputState::selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap&) const
{
	if (selectedButtonPtr == nullptr)
	{
		printDebug(U"[KeyInputState.cpp] KeyInputState::selectButton");
		printDebug(U"selectedButtonPtrがnullptrになってます。");
		return none;
	}

	for (const auto& key : KEY_DIRECTION)
	{
		ButtonPtr adjacentButtonPtr = selectedButtonPtr->getAdjacentButton(key.second);
		
		if (key.first.up || adjacentButtonPtr != nullptr)
		{
			selectedButtonPtr = adjacentButtonPtr;
		}
	}

	if (decesion())
	{
		return selectedButtonPtr->getName();
	}

	return none;
}
