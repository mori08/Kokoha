#include "PlayingState.h"
#include "../GameManager.h"
#include "../../Input/InputManager.h"


void Kokoha::PlayingState::update()
{
	if (InputManager::instance().cancel())
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
