#include "PlayingState.h"
#include "../GameManager.h"


void Kokoha::PlayingState::update()
{
	GameManager::instance().update();
}


void Kokoha::PlayingState::draw() const
{
	GameManager::instance().draw();
}
