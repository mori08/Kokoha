#include "BoxRobot.h"


namespace
{
	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(120, 60);

	// 壊れ
	const Kokoha::Animation BROKEN_ANIM
	(
		0.0,
		Array<Point>{Point(0, 1)},
		false
	);

	// 修理
	const Kokoha::Animation REPAIR_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// 目覚め
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
