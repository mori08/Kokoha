#include "InputManager.h"
#include "MouseInputState.h"
#include "KeyInputState.h"


Kokoha::InputManager::InputManager()
	: mInputState(std::make_unique<KeyInputState>())
{

}


void Kokoha::InputManager::changeInputState()
{
	if ((MouseL | MouseR).up() && Scene::Rect().mouseOver())
	{
		mInputState = std::make_unique<MouseInputState>();
		return;
	}

	if ((KeyEnter | KeyBackspace).up())
	{
		mInputState = std::make_unique<KeyInputState>();
	}
}
