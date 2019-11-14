#include "Equipment.h"


Kokoha::Equipment::Equipment(int32 state)
	: mUsedSecond(0)
	, mTotalCost(0)
	, mCassetteState(state)
{
}


void Kokoha::Equipment::addCassette(const CassettePtr& cassette)
{
	// Šù‚É‘•”õ‚³‚ê‚Ä‚¢‚é‚Æ‚«
	if (mCassetteList.count(cassette)) { return; }

	mCassetteList.insert(cassette);
	mTotalCost += cassette->COST;
	cassette->setState(mCassetteState);
}


void Kokoha::Equipment::removeCassette(const CassettePtr& cassette)
{
	// Šù‚É‘•”õ‚³‚ê‚Ä‚¢‚é‚Æ‚«
	if (!mCassetteList.count(cassette)) { return; }

	mCassetteList.erase(cassette);
	mTotalCost -= cassette->COST;
	cassette->setState(Cassette::POSSESS_STATE);
}


void Kokoha::Equipment::initEffect()
{
	mUsedSecond = 0;

	mEffectQueue.clear();

	for (auto& cassette : mCassetteList)
	{
		mEffectQueue.emplace_back(cassette->EFFECT);
	}

	mEffectQueue.sort();
}


void Kokoha::Equipment::updateEffect()
{
	mUsedSecond += Scene::DeltaTime();

	while (!mEffectQueue.empty() && mEffectQueue.front().BEGIN_SECOND > mUsedSecond)
	{
		mEffectQueue.front().EFFECT_FUNCTION();
	}
}
