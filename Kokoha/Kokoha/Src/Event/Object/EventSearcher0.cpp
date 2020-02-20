#include "EventSearcher0.h"


namespace 
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(40, 40);

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
		0.5,
		Array<Point>{Point(1, 0), Point(0, 0)},
		true
	);
}


Kokoha::EventSearcher0::EventSearcher0(const Point& pos)
	: EventObject(pos, U"Searcher0", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Wait", WAIT_ANIM);
	setAnimation(U"Walk", WALK_ANIM);
}
