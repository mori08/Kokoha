#include "BoxRobot.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(120, 60);

	// ���
	const Kokoha::Animation BROKEN_ANIM
	(
		0.0,
		Array<Point>{Point(0, 1)},
		false
	);

	// �C��
	const Kokoha::Animation REPAIR_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// �ڊo��
	const Kokoha::Animation AWAKE_ANIM
	(
		0.0,
		Array<Point>{Point(1, 0)},
		false
	);
}


Kokoha::BoxRobot::BoxRobot(const Point& pos)
	: EventObject(pos, U"BoxRobot", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Broken", BROKEN_ANIM);
	setAnimation(U"Repair", REPAIR_ANIM);
	setAnimation(U"Awake" ,  AWAKE_ANIM);
}
