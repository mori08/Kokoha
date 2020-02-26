#include "EntranceGate.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(390, 280);

	// �J��
	const Kokoha::Animation OPEN_ANIM
	(
		3.0,
		Array<Point>{Point(0, 1), Point(0, 2), Point(0, 3)},
		false
	);

	// �܂�
	const Kokoha::Animation CLOSE_ANIM
	(
		3.0,
		Array<Point>{Point(0, 2), Point(0, 1)},
		false
	);

	// ��
	const Kokoha::Animation LOCK_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);
}


Kokoha::EntranceGate::EntranceGate(const Point& pos)
	: EventObject(pos, U"OpenEntranceGate", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Open" ,  OPEN_ANIM);
	setAnimation(U"Close", CLOSE_ANIM);
	setAnimation(U"Lock" ,  LOCK_ANIM);
}
