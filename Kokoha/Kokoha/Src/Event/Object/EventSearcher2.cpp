#include "EventSearcher2.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(60, 140);

	// �҂����[�V����
	const Kokoha::Animation WAIT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// �������[�V����
	const Kokoha::Animation WALK_ANIM
	(
		0.6,
		Array<Point>{Point(1, 0), Point(2, 0)},
		true
	);
}


Kokoha::EventSearcher2::EventSearcher2(const Point& pos)
	: EventObject(pos, U"Searcher2", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Wait", WAIT_ANIM);
	setAnimation(U"Walk", WALK_ANIM);
}
