#include "Cassette.h"
#include "../CassetteManager.h"
#include "../../Game/GameManager.h"


int32 Kokoha::Cassette::sNum = 0;


Kokoha::Cassette::Cassette(const String& name, int32 cost, const CassetteEffect& effect)
	: ID(sNum++)
	, mState(NO_POSSESS_STATE)
	, NAME(name)
	, COST(cost)
	, EFFECT(effect)
{
}


Kokoha::CassetteEffect Kokoha::Cassette::makeSpeedEffect(double speed, const std::pair<double, double>& term)
{
	return CassetteEffect
	(
		term.first, 
		[speed, term]()
		{
			GameManager::instance().setSpeedChange(speed, term);
		}
	);
}
