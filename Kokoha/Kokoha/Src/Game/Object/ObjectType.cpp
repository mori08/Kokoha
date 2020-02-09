#include "ObjectType.h"


namespace Kokoha
{
	const ObjectType ObjectType::PLAYER     (1 << 0);
	const ObjectType ObjectType::BLACK_ENEMY(1 << 1);
	const ObjectType ObjectType::WHITE_ENEMY(1 << 2);
	const ObjectType ObjectType::ENEMY      (ObjectType::BLACK_ENEMY | ObjectType::WHITE_ENEMY);
	const ObjectType ObjectType::LIGHT      (1 << 3);
	const ObjectType ObjectType::ATTACK     (1 << 4);
	const ObjectType ObjectType::GOAL       (1 << 5);
	const ObjectType ObjectType::HOLE       (1 << 6);
	const ObjectType ObjectType::KEY        (1 << 7);
}