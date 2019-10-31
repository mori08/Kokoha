#include "GameAttack.h"


namespace
{
	// ���a
	constexpr double RADIUS = 10;

	// �摜�T�C�Y
	constexpr Size TEXTURE_SIZE(24, 24);
}


Kokoha::GameAttack::GameAttack(const Vec2& pos, double speed)
	: GameObject(Circle(pos, RADIUS), ObjectType::ATTACK)
	, mSpeed(speed)
	, mGoal(pos)
	, mIsEraseAble(false)
{
}


void Kokoha::GameAttack::update()
{
	walkToGoal(mSpeed, mGoal);
}


void Kokoha::GameAttack::draw() const
{
	TextureAsset(U"Attack")(Point::Zero(), TEXTURE_SIZE).drawAt(mBody.center);
}


bool Kokoha::GameAttack::isEraseAble() const
{
	return isEraseAble;
}


void Kokoha::GameAttack::checkAnother(const GameObject& another)
{
	// �G�I�u�W�F�N�g�ɓ����������̏���
}
