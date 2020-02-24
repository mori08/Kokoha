#include "MinionEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// ����
	constexpr double SPEED = 0.4;

	// ��]�̔��a
	constexpr double RADIUS = 64;

	// ��]�̊p���x
	constexpr double ANGLE_SPEED = (60 * SPEED) / RADIUS;

	// �v���C���[��ǂ������鋗��
	constexpr double CHASE_DISTANCE = 150;

	// �v���C���[��ǂ������鑬��
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

	// �v���C���[���߂��Ƃ�
	if (playerPos.distanceFrom(mBody.center) < CHASE_DISTANCE)
	{
		walkToGoal(CHASE_SPEED, playerPos);
		return;
	}

	walkToGoal(SPEED, mGoal + RADIUS * angleToVec(mAngle));
}
