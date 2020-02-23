#include "EventRepair2.h"


namespace
{
	// âÊëúÇÃÉTÉCÉY
	constexpr Size TEXTURE_SIZE(80, 120);

	// ë“Çø
	const Kokoha::Animation WAIT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// ï‡Ç´
	const Kokoha::Animation WALK_ANIM
	(
		0.5,
		Array<Point>{Point(0, 0), Point(1, 0)},
		true
	);

	// ì™Çâ∫Ç∞ÇÈ
	const Kokoha::Animation DOWN_ANIM
	(
		1.0,
		Array<Point>{Point(2, 0), Point(3, 0), Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)},
		false
	);

	// ì™Çè„Ç∞ÇÈ
	const Kokoha::Animation UP_ANIM
	(
		1.0,
		Array<Point>{Point(2, 1), Point(1, 1), Point(0, 1), Point(3, 0), Point(2, 0), Point(0, 0)},
		false
	);
}


Kokoha::EventRepair2::EventRepair2(const Point& pos)
	: EventObject(pos, U"Repair2", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Wait", WAIT_ANIM);
	setAnimation(U"Walk", WALK_ANIM);
	setAnimation(U"Down", DOWN_ANIM);
	setAnimation(U"Up"  , UP_ANIM  );
}
