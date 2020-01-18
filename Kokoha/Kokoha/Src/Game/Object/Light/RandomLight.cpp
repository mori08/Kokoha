#include "RandomLight.h"
#include "../../GameManager.h"


namespace
{
	// ����
	constexpr double SPEED = 1.0;

	// ��~����
	constexpr double STOP_DISTANCE = 0.1;

	// ��~����(�b)
	constexpr double STOP_TIME = 3.0;
}


Kokoha::RandomLight::RandomLight(double radius)
	: GameLight(Circle(GameManager::instance().getPlayerPos(), radius* StageData::SQUARE_SIZE), SPEED)
	, mWaitTime(0)
{
}


void Kokoha::RandomLight::update()
{
	// �ړI�n�̕ύX
	if (mWaitTime < 0)
	{
		mGoal = RandomVec2(StageData::SQUARE_SIZE * StageData::WIDTH, StageData::SQUARE_SIZE * StageData::HEIGHT);

		mWaitTime = STOP_TIME;
	}

	// ��~���̏���
	if ((mGoal - mBody.center).length() < STOP_DISTANCE)
	{
		mWaitTime -= Scene::DeltaTime();
	}

	GameLight::update();
}
