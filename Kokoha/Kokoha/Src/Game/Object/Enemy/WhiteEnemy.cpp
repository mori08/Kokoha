#include "WhiteEnemy.h"

Kokoha::WhiteEnemy::WhiteEnemy(const Vec2& pos)
	: GameEnemy(pos, ObjectType::WHITE_ENEMY, U"WhiteEnemy")
{
}


/*
TODO
ƒvƒŒƒCƒ„[‚ÌUŒ‚‚É‚ ‚½‚é‚Æíœ
*/


bool Kokoha::WhiteEnemy::isEraseAble() const
{
	return false;
}

void Kokoha::WhiteEnemy::checkAnother(const GameObject&)
{
	/*
	UŒ‚‚ğ‚¤‚¯‚½‚Æ‚«íœ
	*/
}
