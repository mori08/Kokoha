#include "ClingEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ÉvÉåÉCÉÑÅ[Ç∆ÇÃãóó£
	constexpr double CLING_DISTANCE = 5;

	// ë¨Ç≥
	constexpr double SPEED = 0.5;
}


Kokoha::ClingEnemy::ClingEnemy(const Vec2& pos)
	: BlackEnemy(pos)
	, mGoal(pos)
{

}


void Kokoha::ClingEnemy::update()
{
	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	if (
		!GameManager::instance().getStageData().isWalkAble(mGoal)
		||
		StageData::pixelToInteger(mBody.center) == StageData::pixelToInteger(mGoal)
		)
	{
		mGoal = playerPos + RandomVec2(Circle(Vec2::Zero(), CLING_DISTANCE * StageData::SQUARE_SIZE));
	}

	walkToGoal(SPEED, mGoal);

	BlackEnemy::update();
}
