#include "GameObject.h"
#include "../GameManager.h"


namespace
{
	// プレイヤーの速さの基本値
	constexpr double PLAYER_BASE_SPEED = 60.0;
}


void Kokoha::GameObject::collisionCheck(GameObjectPtr& another)
{
	if (mBody.intersects(another->mBody))
	{
		onCollision(another->mType);
		another->onCollision(mType);
	}
}


void Kokoha::GameObject::walk(Vec2 movement)
{
	movement *= PLAYER_BASE_SPEED * Scene::DeltaTime();

	if (GameManager::instance().getStageData().isWalkAble(mBody.center.movedBy(movement.x, 0)))
	{
		mBody.center.x += movement.x;
	}

	if (GameManager::instance().getStageData().isWalkAble(mBody.center.movedBy(0, movement.y)))
	{
		mBody.center.y += movement.y;
	}
}


void Kokoha::GameObject::walkToGoal(double speed, const Vec2& goal)
{
	walk(speed * GameManager::instance().getStageData().getPath(mBody.center, goal));
}
