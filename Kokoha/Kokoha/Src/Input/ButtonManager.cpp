#include "ButtonManager.h"
#include "../MyLibrary.h"


Kokoha::ButtonManager::ButtonManager()
	: mSelectedButtonPtr(nullptr)
{
	
}


void Kokoha::ButtonManager::registerButton(const String& name, const Rect& region)
{
	mButtonMap[name] = std::make_shared<Button>(name, region);
}


void Kokoha::ButtonManager::registerButton(ButtonPtr button)
{
	mButtonMap[button->getName()] = button;
}


void Kokoha::ButtonManager::setVerticalAdjacentButton(const String& upName, const String& downName)
{
	if (!mButtonMap.count(upName) || !mButtonMap.count(downName))
	{
		printDebug(U"[ButtonManager::setVerticalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"upName > " + upName);
		printDebug(U"downName > " + downName);
		return;
	}

	ButtonPtr upButton   = mButtonMap[upName];
	ButtonPtr downButton = mButtonMap[downName];

	upButton->  setAdjacentButton(Button::Direction::DOWN, downButton);
	downButton->setAdjacentButton(Button::Direction::UP  , upButton  );
}


void Kokoha::ButtonManager::setHorizontalAdjacentButton(const String& leftName, const String& rightName)
{
	if (!mButtonMap.count(leftName) || !mButtonMap.count(rightName))
	{
		printDebug(U"[ButtonManager::setHorizontalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"leftName > " + leftName);
		printDebug(U"rightName > " + rightName);
		return;
	}

	ButtonPtr leftButton  = mButtonMap[leftName];
	ButtonPtr rightButton = mButtonMap[rightName];

	leftButton-> setAdjacentButton(Button::Direction::RIGHT, rightButton);
	rightButton->setAdjacentButton(Button::Direction::LEFT , leftButton );
}


void Kokoha::ButtonManager::setSelectedButton(const String& name)
{
	if (!mButtonMap.count(name))
	{
		printDebug(U"[ButtonManager::setSelectedButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"name > " + name);
		return;
	}

	mSelectedButtonPtr = mButtonMap[name];
}


void Kokoha::ButtonManager::clearButtonList()
{
	mSelectedButtonPtr = nullptr;
	mButtonMap.clear();
}


void Kokoha::ButtonManager::update()
{
	Optional<String> clickedButtonName = InputManager::instatnce().selectButton(mSelectedButtonPtr, mButtonMap);

	if (clickedButtonName && mButtonMap.count(*clickedButtonName))
	{
		mButtonMap[*clickedButtonName]->OnClick();
	}
}
