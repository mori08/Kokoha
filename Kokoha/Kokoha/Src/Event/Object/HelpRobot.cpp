#include "HelpRobot.h"


namespace
{
	// ‰æ‘œ‚ÌƒTƒCƒY
	constexpr Size TEXTURE_SIZE(100, 200);

	// Žè‚ð‹“‚°‚é
	const Kokoha::Animation UP_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(2, 0)},
		false
	);

	// Žè‚ð‰º‚°‚é
	const Kokoha::Animation DOWN_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(0, 0)},
		false
	);
}


Kokoha::HelpRobot::HelpRobot(const Point& pos)
	: EventObject(pos, U"HelpRobot", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Up"  , UP_ANIM  );
	setAnimation(U"Down", DOWN_ANIM);
}
