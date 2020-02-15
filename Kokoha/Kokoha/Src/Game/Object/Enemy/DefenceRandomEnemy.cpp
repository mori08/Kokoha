#include "DefenceRandomEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.8;
}


Kokoha::DefenceRandomEnemy::DefenceRandomEnemy(const Vec2& pos)
	: DefenceEnemy(pos)
{
	mToPos = StageData::integerToPixel(Random(0, StageData::N - 1));
}


void Kokoha::DefenceRandomEnemy::attack()
{
	if (!GameManager::instance().getStageData().isWalkAble(mToPos)
		|| StageData::pixelToInteger(mToPos) == StageData::pixelToInteger(mBody.center))
	{
		mToPos = StageData::integerToPixel(Random(0, StageData::N - 1));
	}

	walkToGoal(SPEED, mToPos);
}
