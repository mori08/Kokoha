#include "WhiteEnemy.h"

Kokoha::WhiteEnemy::WhiteEnemy(const Vec2& pos)
	: GameEnemy(pos, ObjectType::WHITE_ENEMY, U"WhiteEnemy")
{
}


/*
TODO
プレイヤーの攻撃にあたると削除
*/


bool Kokoha::WhiteEnemy::isEraseAble() const
{
	return false;
}

void Kokoha::WhiteEnemy::checkAnother(const GameObject&)
{
	/*
	攻撃をうけたとき削除
	*/
}
