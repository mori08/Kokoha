#include "MinionEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// 速さ
	constexpr double SPEED = 0.4;

	// 回転の半径
	constexpr double RADIUS = 64;

	// 回転の角速度
	constexpr double ANGLE_SPEED = (60 * SPEED) / RADIUS;

	// プレイヤーを追いかける距離
	constexpr double CHASE_DISTANCE = 150;

	// プレイヤーを追いかける速さ
	constexpr double CHASE_SPEED = 0.7;
}


Kokoha::MinionEnemy::MinionEnemy(const Vec2& pos, double angle)
	: BlackEnemy(pos)
	, mGoal(pos)
	, mAngle(angle)
{
}


void Kokoha::MinionEnemy::update()
{
	BlackEnemy::update();

	mAngle += ANGLE_SPEED * Scene::DeltaTime();

	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	// プレイヤーが近いとき
	if (playerPos.distanceFrom(mBody.center) < CHASE_DISTANCE)
	{
		walkToGoal(CHASE_SPEED, playerPos);
		return;
	}

	walkToGoal(SPEED, mGoal + RADIUS * angleToVec(mAngle));
}
