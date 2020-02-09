#include "RandomEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.5;
}


Kokoha::RandomEnemy::RandomEnemy(const Vec2& pos)
	: BlackEnemy(pos)
	, mGoal(pos)
{

}


void Kokoha::RandomEnemy::update()
{
	walkToGoal(SPEED, mGoal);

	if (!GameManager::instance().getStageData().isWalkAble(mGoal)
		|| StageData::pixelToInteger(mGoal) == StageData::pixelToInteger(mBody.center))
	{
		mGoal = StageData::integerToPixel(Random(0, StageData::N - 1));
	}

	BlackEnemy::update();
}
