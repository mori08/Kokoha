#include "EventSearcher1.h"


namespace
{
	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(100, 100);

	// 立ちモーション
	const Kokoha::Animation WAIT_ANIM
	(
		0.0,
		Array<Point>{ Point(0, 0) },
		false
	);

	// 歩きモーション
	const Kokoha::Animation WALK_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(0, 0)},
		true
	);
}


Kokoha::EventSearcher1::EventSearcher1(const Point& pos)
	: EventObject(pos, U"Searcher1", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Wait", WAIT_ANIM);
	setAnimation(U"Walk", WALK_ANIM);
}
