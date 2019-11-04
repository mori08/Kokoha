#include "Equipment.h"


Kokoha::Equipment::Equipment()
	: mUsedSecond(0)
	, mTotalCost(0)
{
}


void Kokoha::Equipment::addCassette(const CassettePtr& cassette)
{
	// 既に装備されているとき
	if (mCassetteList.count(cassette->NAME)) { return; }
	
	mCassetteList[cassette->NAME] = cassette;
	mTotalCost += cassette->COST;
}


void Kokoha::Equipment::removeCassette(const String& name)
{
	// 装備されていないカセットが指定されたとき
	if (!mCassetteList.count(name)) { return; }

	mTotalCost -= mCassetteList[name]->COST;
	mCassetteList.erase(name);
}


void Kokoha::Equipment::initEffect()
{
	mUsedSecond = 0;

	mEffectQueue.clear();

	for (auto& cassette : mCassetteList)
	{
		mEffectQueue.emplace_back(cassette.second->EFFECT);
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
