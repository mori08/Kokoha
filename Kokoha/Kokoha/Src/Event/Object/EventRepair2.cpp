#include "EventRepair2.h"


namespace
{
	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(80, 120);

	// 待ち
	const Kokoha::Animation WAIT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// 歩き
	const Kokoha::Animation WALK_ANIM
	(
		0.5,
		Array<Point>{Point(0, 0), Point(1, 0)},
		true
	);

	// 頭を下げる
	const Kokoha::Animation DOWN_ANIM
	(
		1.0,
		Array<Point>{Point(2, 0), Point(3, 0), Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)},
		false
	);

	// 頭を上げる
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
