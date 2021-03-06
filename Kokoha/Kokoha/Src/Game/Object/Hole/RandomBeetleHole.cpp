#include "RandomBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace 
{
	// 敵を生成する間隔
	const double GENERATE_SPAN = 1.5;

	// 速さ
	const double SPEED = 0.6;

	// 目的地変更距離
	const double CHANGE_GOAL_DISTANCE = 5.0;
}


Kokoha::RandomBeetleHole::RandomBeetleHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
	, mGoal(pos)
{

}


void Kokoha::RandomBeetleHole::update()
{
	walkToGoal(SPEED, mGoal);

	if (mBody.center.distanceFrom(mGoal) < CHANGE_GOAL_DISTANCE
		|| !GameManager::instance().getStageData().isWalkAble(mGoal))
	{
		mGoal = StageData::integerToPixel(Random(0, StageData::N - 1));
	}

	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
		mGenerateSpan.restart();
	}

	GameHole::update();
}
