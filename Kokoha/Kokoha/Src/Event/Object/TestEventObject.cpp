#include "TestEventObject.h"


namespace
{
	// 眠りアニメーション
	const Kokoha::Animation SLEEP_ACT
	(
		1.0,
		Array<Point>{ Point(0,1),Point(1,1),Point(2,1),Point(3,1) },
		true
	);

	// 瞬きアニメーション
	const Kokoha::Animation BLINK_ACT
	(
		0.5,
		Array<Point>{ Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0), Point(2, 0), Point(1, 0), Point(0, 0) },
		false
	);
}


Kokoha::TestEventObject::TestEventObject(const Point& pos)
	: EventObject(pos, U"BoxRobot", Size(30, 30), Point::Zero())
{
	setAnimation(U"Sleep", SLEEP_ACT);
	setAnimation(U"Blink", BLINK_ACT);
}
