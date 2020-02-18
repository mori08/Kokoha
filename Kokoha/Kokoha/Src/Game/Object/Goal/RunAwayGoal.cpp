#include "RunAwayGoal.h"
#include "../../GameManager.h"


namespace
{
	// ����
	constexpr double SPEED = 1.5;

	// �ړI�n��ύX�̎���
	constexpr double MAX_CHANGE_GOAL_SECOND = 0.1;

	// �]���l�̔䗦
	constexpr double RATE = 1.5;
}


Kokoha::RunAwayGoal::RunAwayGoal(const Vec2& pos)
	: GameGoal(pos, SPEED)
	, mChangeGoalSecond(0)
{
}


void Kokoha::RunAwayGoal::update()
{
	mChangeGoalSecond -= Scene::DeltaTime();

	if (mChangeGoalSecond < 0)
	{
		mChangeGoalSecond = MAX_CHANGE_GOAL_SECOND;

		mGoal = GameManager::instance().getStageData().getRunAwayPixel(mBody.center);
	}

	GameGoal::update();
}
