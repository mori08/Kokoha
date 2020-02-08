#include "EggWhiteEnemy.h"


namespace
{
	// ‘¬‚³
	constexpr double SPEED = 0.1;
}


Kokoha::EggWhiteEnemy::EggWhiteEnemy(const Vec2& pos)
	: WhiteEnemy(pos)
	, mAngle(Random(0.0,Math::TwoPi))
{
}


void Kokoha::EggWhiteEnemy::update()
{
	WhiteEnemy::update();

	walk(SPEED * Vec2(Sin(mAngle), Cos(mAngle)));
}
