#include "ButtonManager.h"
#include "../MyLibrary.h"


Kokoha::ButtonManager::ButtonManager()
	: mSelectedButtonPtr(nullptr)
{
	
}


void Kokoha::ButtonManager::registerButton(const String& name, const Rect& region)
{
	mButtonMap[name] = std::make_shared<Button>(name, region);

	// mButtonMapがもともと空だったとき
	if (mButtonMap.size() == 1) { mSelectedButtonPtr = mButtonMap[name]; }
}


void Kokoha::ButtonManager::registerButton(const Button& button)
{
	mButtonMap[button.getName()] = std::make_shared<Button>(button);

	// mButtonMapがもともと空だったとき
	if (mButtonMap.size() == 1) { mSelectedButtonPtr = mButtonMap[button.getName()]; }
}


void Kokoha::ButtonManager::setVerticalAdjacentButton(const String& upName, const String& downName)
{
	if (!mButtonMap.count(upName))
	{
		printDebug(U"[ButtonManager::setVerticalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"upName > " + upName);
		return;
	}

	if (!mButtonMap.count(downName))
	{
		printDebug(U"[ButtonManager::setVerticalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
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
	if (!mButtonMap.count(leftName))
	{
		printDebug(U"[ButtonManager::setHorizontalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"leftName > " + leftName);
		return;
	}

	if (!mButtonMap.count(rightName))
	{
		printDebug(U"[ButtonManager::setHorizontalAdjacentButton]");
		printDebug(U"存在しないボタンが指定されました");
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


void Kokoha::ButtonManager::setOnClickFunc(const String& name, ButtonOnClick onClickFunc)
{
	if (!mButtonMap.count(name))
	{
		printDebug(U"[ButtonManager::setSelectedButton]");
		printDebug(U"存在しないボタンが指定されました");
		printDebug(U"name > " + name);
		return;
	}

	mButtonMap[name]->setOnClickFunc(onClickFunc);
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
