#include "GameAttack.h"


namespace
{
	// 半径
	constexpr double RADIUS = 10;

	// 画像サイズ
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
	// 敵オブジェクトに当たった時の処理
}
