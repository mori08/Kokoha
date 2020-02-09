#include "GameGoalKey.h"
#include "../../../GameManager.h"


namespace
{
	// ”¼Œa
	constexpr double RADIUS = 8;

	// ‘¬‚³
	constexpr double SPEED = 1.2;

	// ‰æ‘œ‚ÌƒTƒCƒY
	constexpr Size TEXTURE_SIZE(24, 24);
}


Kokoha::GameGoalKey::GameGoalKey(const Vec2& pos)
	: GameObject(Circle(pos, RADIUS), ObjectType::KEY)
	, mIsChecked(false)
	, mGoal(pos)
{
}


void Kokoha::GameGoalKey::update()
{
	if (mIsChecked) { return; }

	if (!GameManager::instance().getStageData().isWalkAble(mGoal)
		|| StageData::pixelToInteger(mBody.center) == StageData::pixelToInteger(mGoal))
	{
		mGoal = StageData::integerToPixel(Random(0, StageData::N - 1));
	}

	walkToGoal(SPEED, mGoal);
}


void Kokoha::GameGoalKey::draw() const
{
	const Point pos(mIsChecked ? TEXTURE_SIZE.x : 0, 0);
	TextureAsset(U"GoalKey")(pos, TEXTURE_SIZE).drawAt(mBody.center);
}


void Kokoha::GameGoalKey::checkAnother(const GameObject& another)
{
	if (checkTypeAndCollision(another, ObjectType::PLAYER))
	{
		mIsChecked = true;
	}
}
