#include "MouseInputState.h"


bool Kokoha::MouseInputState::decesion() const
{
	return MouseL.up;
}


bool Kokoha::MouseInputState::cancel() const
{
	return MouseR.up;
}


Optional<String> Kokoha::MouseInputState::selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const
{
	for (auto itr = buttonPtrMap.begin(); itr != buttonPtrMap.end(); ++itr)
	{
		if (!itr->second->getRegion().mouseOver) { continue; }

		selectedButtonPtr = itr->second;

		if (decesion()) { return itr->first; }

		return none;
	}

	return none;
}
