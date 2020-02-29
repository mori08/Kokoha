#include "PlayingState.h"
#include "../GameManager.h"
#include "../../Input/InputManager.h"


void Kokoha::PlayingState::update()
{
	if (MouseR.up() || KeyBackspace.up())
	{
		GameManager::instance().setPauseState();
		return;
	}

	GameManager::instance().update();
}


void Kokoha::PlayingState::draw() const
{
	GameManager::instance().draw();
}
