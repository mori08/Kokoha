#include "Equipment.h"
#include "../Record/RecordManager.h"


namespace
{
	// �����ł���J�Z�b�g�̏��
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
	// ���ɑ�������Ă���Ƃ�
	if (mCassetteList.count(cassette)) { return; }

	mCassetteList.insert(cassette);
	mTotalCost += cassette->COST;
	cassette->setState(mCassetteState);
}


void Kokoha::Equipment::removeCassette(const CassettePtr& cassette)
{
	// ���ɑ�������Ă���Ƃ�
	if (!mCassetteList.count(cassette)) { return; }

	mCassetteList.erase(cassette);
	mTotalCost -= cassette->COST;
	cassette->setState(Cassette::POSSESS_STATE);
}


bool Kokoha::Equipment::isAddAbleCassette(const CassettePtr& cassette) const
{
	// ��������𒴂����� false
	if (mCassetteList.size() + 1 > NUM_LIMIT) { return false; }

	// �R�X�g����𒴂����� false
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
