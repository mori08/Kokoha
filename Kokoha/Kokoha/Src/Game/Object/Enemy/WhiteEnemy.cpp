#include "WhiteEnemy.h"

Kokoha::WhiteEnemy::WhiteEnemy(const Vec2& pos)
	: GameEnemy(pos, ObjectType::WHITE_ENEMY, U"WhiteEnemy")
{
}


/*
TODO
�v���C���[�̍U���ɂ�����ƍ폜
*/


bool Kokoha::WhiteEnemy::isEraseAble() const
{
	return false;
}

void Kokoha::WhiteEnemy::checkAnother(const GameObject&)
{
	/*
	�U�����������Ƃ��폜
	*/
}
