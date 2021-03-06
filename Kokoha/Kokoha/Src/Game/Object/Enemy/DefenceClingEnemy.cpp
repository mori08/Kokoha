#include "DefenceClingEnemy.h"
#include "../../GameManager.h"


namespace
{
	// プレイヤーに近づく距離
	constexpr double CLING_DISTANCE = 128;

	// 速さ
	constexpr double SPEED = 0.7;
}


Kokoha::DefenceClingEnemy::DefenceClingEnemy(const Vec2& pos)
	: DefenceEnemy(pos)
{
	mToPos = GameManager::instance().getPlayerPos();
}


void Kokoha::DefenceClingEnemy::attack()
{
	if (!GameManager::instance().getStageData().isWalkAble(mToPos)
		|| StageData::pixelToInteger(mBody.center) == StageData::pixelToInteger(mToPos))
	{
		mToPos
			= GameManager::instance().getPlayerPos()
			+ RandomVec2(Circle(Vec2::Zero(), CLING_DISTANCE));
	}

	walkToGoal(SPEED, mToPos);
}
