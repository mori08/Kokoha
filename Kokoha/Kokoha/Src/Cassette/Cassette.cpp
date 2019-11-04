#include "Cassette.h"


Kokoha::Cassette::Cassette(const String& name, int32 cost, const CassetteEffect& effect)
	: mUsed(false)
	, NAME(name)
	, COST(cost)
	, EFFECT(effect)
{
}
