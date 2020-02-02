#include "Equipment.h"
#include "../Record/RecordManager.h"


namespace
{
	// 装備できるカセットの上限
	constexpr int32 NUM_LIMIT = 6;
}


Kokoha::Equipment::Equipment(int32 state)
	: mUsedSecond(0)
	, mTotalCost(0)
	, mCassetteState(state)
{
}


void Kokoha::Equipment::addCassette(const CassettePtr& cassette)
{
	// 既に装備されているとき
	if (mCassetteList.count(cassette)) { return; }

	mCassetteList.insert(cassette);
	mTotalCost += cassette->COST;
	cassette->setState(mCassetteState);
}


void Kokoha::Equipment::removeCassette(const CassettePtr& cassette)
{
	// 既に装備されているとき
	if (!mCassetteList.count(cassette)) { return; }

	mCassetteList.erase(cassette);
	mTotalCost -= cassette->COST;
	cassette->setState(Cassette::POSSESS_STATE);
}


bool Kokoha::Equipment::isAddAbleCassette(const CassettePtr& cassette) const
{
	// 所持上限を超えたら false
	if (mCassetteList.size() + 1 > NUM_LIMIT) { return false; }

	// コスト上限を超えたら false
	if (mTotalCost + cassette->COST > RecordManager::instance().getRecord(U"CassetteCapacity")) { return false; }

	return true;
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

	while (!mEffectQueue.empty() && mEffectQueue.front().BEGIN_SECOND < mUsedSecond)
	{
		mEffectQueue.front().EFFECT_FUNCTION();
		mEffectQueue.pop_front();
	}
}
