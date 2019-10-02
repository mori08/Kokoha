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


inline void Kokoha::Button::setAdjacentButton(const Direction& direction, ButtonPtr adjacentButtonPtr)
{
	mAdjacentButtonMap[direction] = adjacentButtonPtr;
}


inline std::shared_ptr<Kokoha::Button> Kokoha::Button::getAdjacentButton(const Direction& direction)
{
	return mAdjacentButtonMap[direction];
}


inline const String& Kokoha::Button::getName() const
{
	return mName;
}


inline const Rect& Kokoha::Button::getRegion() const
{
	return mRegion;
}
