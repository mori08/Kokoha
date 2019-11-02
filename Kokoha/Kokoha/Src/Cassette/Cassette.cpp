#include "Cassette.h"


Kokoha::Cassette::Cassette(const String& name, int32 cost, const std::pair<double, double>& term, const std::function<void()>& effect)
	: mUsed(false)
	, NAME(name)
	, COST(cost)
	, TERM(term)
	, EFFECT(effect)
{
}
