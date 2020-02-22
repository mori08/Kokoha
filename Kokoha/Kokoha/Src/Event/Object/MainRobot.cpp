#include "MainRobot.h"


namespace
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(60, 60);

	// �O����
	const Kokoha::Animation FRONT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// �����
	const Kokoha::Animation BACK_ANIM
	(
		0.0,
		Array<Point>{Point(2, 2)},
		false
	);

	// ������
	const Kokoha::Animation SIDE_ANIM
	(
		0.0,
		Array<Point>{Point(0, 2)},
		false
	);

	// ����
	const Kokoha::Animation WALK_ANIM
	(
		0.3,
		Array<Point>{Point(1, 2), Point(0, 2)},
		true
	);

	// �u��
	const Kokoha::Animation BLINK_ANIM
	(
		0.3,
		Array<Point>{Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0), Point(2, 0), Point(1, 0), Point(0, 0)},
		false
	);

	// �ڂ���Ă���
	const Kokoha::Animation SLEEP_ANIM
	(
		0.0,
		Array<Point>{Point(3, 0)},
		false
	);

	// �ڂ��J����
	const Kokoha::Animation AWAKE_ANIM
	(
		0.4,
		Array<Point>{Point(3, 0), Point(2, 0), Point(1, 0), Point(0, 0)},
		false
	);
}


Kokoha::MainRobot::MainRobot(const Point& pos)
	: EventObject(pos, U"MainRobot", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Front", FRONT_ANIM);
	setAnimation(U"Back" , BACK_ANIM );
	setAnimation(U"Side" , SIDE_ANIM );

	setAnimation(U"Walk" , WALK_ANIM );
	setAnimation(U"Blink", BLINK_ANIM);

	setAnimation(U"Sleep", SLEEP_ANIM);
	setAnimation(U"Awake", AWAKE_ANIM);
}
