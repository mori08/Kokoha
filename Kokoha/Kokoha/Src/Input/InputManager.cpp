#include "InputManager.h"
#include "MouseInputState.h"
#include "KeyInputState.h"


Kokoha::InputManager::InputManager()
	: mInputState(std::make_unique<MouseInputState>())
{

}


Kokoha::InputManager& Kokoha::InputManager::instatnce()
{
	static InputManager inputManager;
	return inputManager;
}


bool Kokoha::InputManager::decision() const
{
	return mInputState->decesion();
}


bool Kokoha::InputManager::cancel() const
{
	return mInputState->cancel();
}


void Kokoha::InputManager::changeInputState()
{
	if ((MouseL | MouseR).up())
	{
		mInputState = std::make_unique<MouseInputState>();
		return;
	}

	if ((KeyW | KeyA | KeyS | KeyD | KeyEnter | KeyBackspace).up())
	{
		mInputState = std::make_unique<KeyInputState>();
	}
}
