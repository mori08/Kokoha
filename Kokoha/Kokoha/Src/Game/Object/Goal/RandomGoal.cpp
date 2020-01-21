#include "RandomGoal.h"
#include "../../GameManager.h"


namespace Kokoha
{
	// ����
	constexpr double SPEED = 0.5;

	// �ړI�n��ύX���鋗��
	constexpr double CHANGE_GOAL_DISTANCE = 2.0;

	// �]���l�̔�
	constexpr double RATE = 1.2;

	// ���_�̌�
	constexpr int32 POINT_NUM = 3;
}


Kokoha::RandomGoal::RandomGoal(const Vec2& pos)
	: GameGoal(pos, SPEED)
{
}


void Kokoha::RandomGoal::update()
{
	// �ړI�n�ɏ[���ɋ߂Â����Ƃ� �ړI�n�ύX
	if ((mBody.center - mGoal).length() < CHANGE_GOAL_DISTANCE)
	{
		double minDistance = Inf<double>;
		Vec2   playerPos   = GameManager::instance().getPlayerPos();

		// ��N �̃����_���ɑI�΂ꂽ���_���l����
		for (int32 i = 0; i < POINT_NUM; ++i)
		{
			Vec2 nextGoal
				= RandomVec2(RectF(Vec2::Zero(), StageData::SQUARE_SIZE * Vec2(StageData::WIDTH, StageData::HEIGHT)));

			if (!GameManager::instance().getStageData().isWalkAble(nextGoal)) { continue; }

			double distance
				= GameManager::instance().getStageData().getDistance(mBody.center, nextGoal)
				- RATE*GameManager::instance().getStageData().getDistance(playerPos   , nextGoal);

			if (distance > minDistance) { continue; }

			minDistance = distance;
			mGoal       = nextGoal;
		}
	}

	GameGoal::update();
}
