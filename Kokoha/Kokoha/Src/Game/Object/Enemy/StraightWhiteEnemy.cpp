#include "StraightWhiteEnemy.h"


Kokoha::StraightWhiteEnemy::StraightWhiteEnemy(const Vec2& pos, const Vec2& movement)
	: WhiteEnemy(pos)
	, mMovement(movement)
{

}


void Kokoha::StraightWhiteEnemy::update()
{
	walk(mMovement);

	WhiteEnemy::update();
}
