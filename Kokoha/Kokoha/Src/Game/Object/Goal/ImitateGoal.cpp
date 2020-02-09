#include "ImitateGoal.h"
#include "../../GameManager.h"


Kokoha::ImitateGoal::ImitateGoal(const Vec2& pos)
	: GameGoal(pos)
{

}


void Kokoha::ImitateGoal::update()
{
	Point direction = Point::Zero();

	// ƒL[“ü—Í‚É‰‚¶‚ÄˆÚ“®•ûŒü‚ğŒˆ’è
	if (KeyW.pressed()) { direction += Point::Up(); }
	if (KeyA.pressed()) { direction += Point::Left(); }
	if (KeyS.pressed()) { direction += Point::Down(); }
	if (KeyD.pressed()) { direction += Point::Right(); }

	walk(GameManager::instance().getPlayerSpeed() * direction);

	GameGoal::update();
}
