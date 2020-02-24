#include "HelpRobot.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(100, 200);

	// ���������
	const Kokoha::Animation UP_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(2, 0)},
		false
	);

	// ���������
	const Kokoha::Animation DOWN_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(0, 0)},
		false
	);

	// ��
	const Kokoha::Animation OLD_ANIM
	(
		0.0,
		Array<Point>{Point(3, 0)},
		false
	);
}


Kokoha::HelpRobot::HelpRobot(const Point& pos)
	: EventObject(pos, U"HelpRobot", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Up"  , UP_ANIM  );
	setAnimation(U"Down", DOWN_ANIM);

	setAnimation(U"Old", OLD_ANIM);
}
