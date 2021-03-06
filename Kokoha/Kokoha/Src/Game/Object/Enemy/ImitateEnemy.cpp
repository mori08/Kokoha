#include "ImitateEnemy.h"
#include "../../GameManager.h"


Kokoha::ImitateEnemy::ImitateEnemy(const Vec2& pos)
	: BlackEnemy(pos)
{
}


void Kokoha::ImitateEnemy::update()
{
	BlackEnemy::update();

	Point direction = Point::Zero();

	// キー入力に応じて移動方向を決定
	if (KeyW.pressed()) { direction += Point::Up(); }
	if (KeyA.pressed()) { direction += Point::Left(); }
	if (KeyS.pressed()) { direction += Point::Down(); }
	if (KeyD.pressed()) { direction += Point::Right(); }

	walk(GameManager::instance().getPlayerSpeed() * direction);
}
