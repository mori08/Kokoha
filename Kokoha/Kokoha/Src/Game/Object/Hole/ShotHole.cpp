#include "ShotHole.h"
#include "../Enemy/StraightWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// �����Ԋu
	constexpr double GENERATE_SPAN = 6.0;

	// �S�[���Ƃ̋���
	constexpr double DISTANCE = 96;

	// ����
	constexpr double SPEED = 0.8;

	// �����G��ł��o������
	constexpr double SHOT_SPEED = 1.5;
}


Kokoha::ShotHole::ShotHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
{
}


void Kokoha::ShotHole::update()
{
	const Vec2 movement = SHOT_SPEED*(mPlayerPos - mBody.center).normalized();

	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject
		(
			std::make_unique<StraightWhiteEnemy>(mBody.center, movement)
		);
		mGenerateSpan.restart();
	}

	const Vec2 goal = mGoalPos + DISTANCE*(mGoalPos - mPlayerPos).normalized();

	walkToGoal(SPEED, goal);

	GameHole::update();
}


void Kokoha::ShotHole::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoalPos = pos.value();
	}

	if (auto pos = another.checkTypeAndGetPos(ObjectType::PLAYER))
	{
		mPlayerPos = pos.value();
	}

	GameHole::checkAnother(another);
}
