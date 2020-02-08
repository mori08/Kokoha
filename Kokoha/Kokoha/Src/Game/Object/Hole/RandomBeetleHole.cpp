#include "RandomBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace 
{
	// �G�𐶐�����Ԋu
	const double GENERATE_SPAN = 1.0;

	// ����
	const double SPEED = 0.6;

	// �ړI�n�ύX����
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
