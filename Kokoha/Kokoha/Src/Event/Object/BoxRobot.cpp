#include "BoxRobot.h"


namespace
{
	// âÊëúÇÃÉTÉCÉY
	constexpr Size TEXTURE_SIZE(120, 60);

	// âÛÇÍ
	const Kokoha::Animation BROKEN_ANIM
	(
		0.0,
		Array<Point>{Point(0, 1)},
		false
	);

	// èCóù
	const Kokoha::Animation REPAIR_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);
}


Kokoha::BoxRobot::BoxRobot(const Point& pos)
	: EventObject(pos, U"BoxRobot", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Broken", BROKEN_ANIM);
	setAnimation(U"Repair", REPAIR_ANIM);
}
