#include "InputManager.h"
#include "MouseInputState.h"
#include "KeyInputState.h"


Kokoha::InputManager::InputManager()
	: mInputState(std::make_unique<MouseInputState>())
{

}


void Kokoha::InputManager::changeInputState()
{
	if ((MouseL | MouseR).up() && Scene::Rect().mouseOver())
	{
		mInputState = std::make_unique<MouseInputState>();
		return;
	}

	if ((KeyW | KeyA | KeyS | KeyD | KeyEnter | KeyBackspace).up())
	{
		mInputState = std::make_unique<KeyInputState>();
	}
}
