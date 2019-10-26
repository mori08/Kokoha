#include "GameObject.h"
#include "../GameManager.h"


namespace
{
	// プレイヤーの速さの基本値
	constexpr double PLAYER_BASE_SPEED = 60.0;
}


void Kokoha::GameObject::walk(Vec2 movement)
{
	movement *= PLAYER_BASE_SPEED * Scene::DeltaTime();

	if (GameManager::instance().getStageData().isWalkAble(mPos.movedBy(movement.x, 0)))
	{
		mPos.x += movement.x;
	}

	if (GameManager::instance().getStageData().isWalkAble(mPos.movedBy(0, movement.y)))
	{
		mPos.y += movement.y;
	}
}


void Kokoha::GameObject::walkToGoal(double speed, const Vec2& goal)
{
	walk(speed * GameManager::instance().getStageData().getPath(mPos, goal));
}
