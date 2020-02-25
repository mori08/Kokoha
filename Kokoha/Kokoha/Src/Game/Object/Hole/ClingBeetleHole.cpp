#include "ClingBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// 敵の生成間隔
	constexpr double GENERATE_SPAN = 1.5;

	// 速さ
	constexpr double SPEED = 0.8;

	// 目的地設定時のプレイヤーとの距離
	constexpr double DISTANCE_FROM_PLAYER = 64;
}


Kokoha::ClingBeetleHole::ClingBeetleHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
	, mGoal(pos)
{
}


void Kokoha::ClingBeetleHole::update()
{
	walkToGoal(SPEED, mGoal);

	if (!GameManager::instance().getStageData().isWalkAble(mGoal)
		|| StageData::pixelToInteger(mBody.center) == StageData::pixelToInteger(mGoal))
	{
		mGoal = GameManager::instance().getPlayerPos()
			  + DISTANCE_FROM_PLAYER * angleToVec(Random(0.0, Math::TwoPi));
	}

	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
		mGenerateSpan.restart();
	}

	GameHole::update();
}
