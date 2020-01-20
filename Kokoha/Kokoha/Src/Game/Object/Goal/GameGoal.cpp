#include "GameGoal.h"


namespace
{
	// 当たり判定の半径
	constexpr double RADIUS = 3.0;

	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(32, 32);

	// ゴールできるときのアニメーション
	const Kokoha::Animation UNLOCK_ANIMATION
	(
		0.5,
		Array<Point>{Point(0, 0), Point(1, 0), Point(2, 0)},
		true
	);

	// ゴールできないときのアニメーション
	const Kokoha::Animation LOCK_ANIMATION
	(
		0,
		Array<Point>{Point(3, 0)},
		false
	);
}


Kokoha::GameGoal::GameGoal(const Vec2& pos, double speed)
	: GameObject(Circle(pos, RADIUS), ObjectType::GOAL)
	, mGoal(pos)
	, mSpeed(speed)
	, mSlide(U"Goal", TEXTURE_SIZE, Point::Zero())
{
	mSlide.setAnimation(U"unlock", UNLOCK_ANIMATION);
	mSlide.setAnimation(U"lock", LOCK_ANIMATION);

	mSlide.start(U"unlock");
}


void Kokoha::GameGoal::update()
{
	walkToGoal(mSpeed, mGoal);

	mSlide.changeTexture();
}


void Kokoha::GameGoal::draw() const
{
	mSlide.getTexture().drawAt(mBody.center);
}


void Kokoha::GameGoal::checkAnother(const GameObject& another)
{
	// TODO : クリアの処理
}
