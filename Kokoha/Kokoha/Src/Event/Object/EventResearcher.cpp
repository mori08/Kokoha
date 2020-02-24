#include "EventResearcher.h"


namespace
{
	// �摜�T�C�Y
	constexpr Size TEXTURE_SIZE(80, 80);

	// �O
	const Kokoha::Animation FRONT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 0)},
		false
	);

	// �ڂ����
	const Kokoha::Animation SLEEP_ANIM
	(
		0.5,
		Array<Point>{Point(1, 0), Point(2, 0), Point(3, 0)},
		false
	);

	// �ڂ��J����
	const Kokoha::Animation AWAKE_ANIM
	(
		0.5,
		Array<Point>{Point(2, 0), Point(1, 0), Point(0, 0)},
		false
	);

	// �l����
	const Kokoha::Animation THINK_ANIM
	(
		2.5,
		Array<Point>{Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1), Point(3, 0)},
		false
	);

	// �E����
	const Kokoha::Animation RIGHT_ANIM
	(
		0.0,
		Array<Point>{Point(2, 2)},
		false
	);

	// �E����
	const Kokoha::Animation RIGHT_WALK_ANIM
	(
		0.5,
		Array<Point>{Point(3, 2), Point(2, 2)},
		true
	);
	
	// ������
	const Kokoha::Animation LEFT_ANIM
	(
		0.0,
		Array<Point>{Point(0, 2)},
		false
	);

	// ������
	const Kokoha::Animation LEFT_WALK_ANIM
	(
		0.5,
		Array<Point>{Point(1, 2), Point(0, 2)},
		true
	);
}


Kokoha::EventResearcher::EventResearcher(const Point& pos)
	: EventObject(pos, U"Researcher", TEXTURE_SIZE, Point::Zero())
{
	setAnimation(U"Front", FRONT_ANIM);
	setAnimation(U"Sleep", SLEEP_ANIM);
	setAnimation(U"Awake", AWAKE_ANIM);
	setAnimation(U"Think", THINK_ANIM);

	setAnimation(U"Right", RIGHT_ANIM);
	setAnimation(U"Left" ,  LEFT_ANIM);

	setAnimation(U"RightWalk", RIGHT_WALK_ANIM);
	setAnimation( U"LeftWalk",  LEFT_WALK_ANIM);
}
