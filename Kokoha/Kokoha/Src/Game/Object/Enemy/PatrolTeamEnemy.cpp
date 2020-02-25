#include "PatrolTeamEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// �ړ��̑���
	constexpr double SPEED = 0.8;

	// �ǂ������鑬��
	constexpr double CHASE_SPEED = 2.0;

	// �ǂ������n�߂鋗��
	constexpr double CHASE_DISTANCE = 64;

	// �ړI�n��ύX���鎞�Ԃ͈̔�
	constexpr std::pair<double, double> CHANGE_GOAL_SECOND_RANGE = { 2.0,4.0 };
}


bool Kokoha::PatrolTeamEnemy::sIsChasing = false;


Kokoha::PatrolTeamEnemy::PatrolTeamEnemy(const Vec2& pos)
	: BlackEnemy(pos)
	, mGoal(pos)
	, mChangeGoalSecond(0)
{
	sIsChasing = false;
}


void Kokoha::PatrolTeamEnemy::update()
{
	BlackEnemy::update();

	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	// �v���C���[���߂Â�����ǂ�������
	if (playerPos.distanceFrom(mBody.center) < CHASE_DISTANCE)
	{
		sIsChasing = true;
	}
	if (sIsChasing)
	{
		walkToGoal(CHASE_SPEED, playerPos);
		return;
	}

	mChangeGoalSecond -= Scene::DeltaTime();

	if (mChangeGoalSecond < 0)
	{
		mGoal = mBody.center + CHASE_DISTANCE * angleToVec(Random(0.0, Math::TwoPi));
		mChangeGoalSecond = Random(CHANGE_GOAL_SECOND_RANGE.first, CHANGE_GOAL_SECOND_RANGE.second);
	}

	walkToGoal(SPEED, mGoal);
}


void Kokoha::PatrolTeamEnemy::draw() const
{
	if (sIsChasing)
	{
		TextureAsset(U"Patrol").drawAt(mBody.center);
	}

	BlackEnemy::draw();
}


void Kokoha::PatrolTeamEnemy::checkAnother(const GameObject& another)
{
	BlackEnemy::checkAnother(another);

	if (sIsChasing) { return; }
	
	if (auto pos = another.checkTypeAndGetPos(ObjectType::ENEMY))
	{
		if ((pos.value()-mBody.center).length() > 2*StageData::SQUARE_SIZE) { return; }
		
		mGoal =
			mBody.center
			+ CHASE_DISTANCE * (mBody.center - pos.value()).normalize()
			+ RandomVec2(Circle(Vec2::Zero(), CHASE_DISTANCE));

		mChangeGoalSecond = Random(CHANGE_GOAL_SECOND_RANGE.first, CHANGE_GOAL_SECOND_RANGE.second);
	}
	
}
