#include "GoalLight.h"
#include "RootingLight.h"
#include "../../GameManager.h"


namespace
{
	// 速さ
	constexpr double SPEED = 2.0;

	// 案内用の光を出す期間
	constexpr double ROOTING_SPAN = 0.3;
}


Kokoha::GoalLight::GoalLight(double radius, double eraseSecond, bool isRooting)
	: GameLight(Circle(GameManager::instance().getPlayerPos(),radius*StageData::SQUARE_SIZE), SPEED, eraseSecond)
	, mIsRooting(isRooting)
	, mRootingSecond(ROOTING_SPAN)
{
	
}


void Kokoha::GoalLight::update()
{
	GameLight::update();

	mRootingSecond -= Scene::DeltaTime();

	if (mIsRooting && mRootingSecond < 0 && !mEraseAble)
	{
		mRootingSecond = ROOTING_SPAN;

		GameManager::instance().addObject(std::make_unique<RootingLight>(mEraseSecond));
	}
}


void Kokoha::GoalLight::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoal        = pos.value();
		mBody.center = pos.value();
	}
}
