#include "Button.h"


Kokoha::Button::Button(const String& name, const Rect& region)
	: mName(name)
	, mRegion(region)
{
	mAdjacentButtonMap[Direction::UP]    = nullptr;
	mAdjacentButtonMap[Direction::DOWN]  = nullptr;
	mAdjacentButtonMap[Direction::LEFT]  = nullptr;
	mAdjacentButtonMap[Direction::RIGHT] = nullptr;
}


void Kokoha::Button::setAdjacentButton(const Direction& direction, ButtonPtr adjacentButtonPtr)
{
	mAdjacentButtonMap[direction] = adjacentButtonPtr;
}


Kokoha::ButtonPtr Kokoha::Button::getAdjacentButton(const Direction& direction) const
{
	return mAdjacentButtonMap.find(direction)->second;
}
