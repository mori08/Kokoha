#include "GamePlayer.h"
#include "../../../MyColor.h"


namespace
{
	// �������[�v�����鎞��(�b)
	constexpr double LIGHT_LOOP_TIME = 2.0;
	// ���̌���
	constexpr double LIGHT_THICKNESS = 2.5;
	// ���̔��a�̍ő�l
	constexpr double LIGHT_RADIUS = 40.0;
	// ���̔��a�ɂ�����w��
	constexpr double RADIUS_POW = 0.3;
	// ���̕s�����x�ɂ�����w��
	constexpr double ALPHA_POW = 1.2;
}


Kokoha::GamePlayer::GamePlayer(const Vec2& pos)
	: GameObject(pos, ObjectType::PLAYER)
	, mLightRate(LIGHT_LOOP_TIME, 1.0)
{

}


void Kokoha::GamePlayer::update()
{
	// �ړ�
	Point direction = Point::Zero();
	if (KeyW.pressed()) { direction += Point::Up();    }
	if (KeyS.pressed()) { direction += Point::Down();  }
	if (KeyA.pressed()) { direction += Point::Left();  }
	if (KeyD.pressed()) { direction += Point::Right(); }
	walk(1.0 * direction);

	// ��
	if (mLightRate.update()) { mLightRate.restart(); }
}


void Kokoha::GamePlayer::draw() const
{
	TextureAsset(U"Player").drawAt(mPos);
}


void Kokoha::GamePlayer::drawLight() const
{
	const double rate = mLightRate.getValue();

	const ColorF color(MyWhite, 1.0 - pow(rate, ALPHA_POW));

	const double radius = LIGHT_RADIUS * pow(rate, RADIUS_POW);

	Circle(mPos, radius).drawFrame(LIGHT_THICKNESS, color);
}
