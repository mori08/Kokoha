#include "Cassette.h"
#include "../CassetteManager.h"
#include "../../Game/GameManager.h"


Kokoha::Cassette::Cassette(const String& name, int32 cost, const CassetteEffect& effect)
	: mUsed(false)
	, NAME(name)
	, COST(cost)
	, EFFECT(effect)
{
}


Kokoha::CassetteEffect&& Kokoha::Cassette::getSpeedEffect(double speed, const std::pair<double, double>& term)
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
