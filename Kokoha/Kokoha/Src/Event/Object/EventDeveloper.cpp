#include "EventDeveloper.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(120, 240);

	// �҂�
	const Kokoha::Animation WAIT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// ����
	const Kokoha::Animation WALK_ANIM
	(
		1.0,
		Array<Point>{Point(1, 0), Point(0, 0)},
		true
	);

	// ����
	const Kokoha::Animation SIT_ANIM
	(
		0.7,
		Array<Point>{Point(2, 0), Point(3, 0), Point(4, 0)},
		false
	);

	// ����
	const Kokoha::Animation STAND_ANIM
	(
		0.7,
		Array<Point>{Point(3, 0), Point(2, 0), Point(0, 0)},
		false
	);
}


Kokoha::EventDeveloper::EventDeveloper(const Point& pos)
	: EventObject(pos, U"Developer", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Wait" , WAIT_ANIM );
	setAnimation(U"Walk" , WALK_ANIM );
	setAnimation(U"Sit"  , SIT_ANIM  );
	setAnimation(U"Stand", STAND_ANIM);
}
