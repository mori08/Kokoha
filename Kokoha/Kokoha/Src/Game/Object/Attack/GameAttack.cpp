#include "GameAttack.h"
#include "../../../MyLibrary.h"


namespace
{
	// 半径
	constexpr double RADIUS = 10;

	// 画像サイズ
	constexpr Size TEXTURE_SIZE(24, 24);

	// 画像番号
	const Array<Point> TEXTURE_POS{ Point::Zero(),Point(24,0) };
	// 回転速度
	const Array<double> ANGLE_SPEED{ 0.25 , 0.75 };

	// 回転角の変更の割合
	constexpr double ANGLE_RATE = 0.01;
}


Kokoha::GameAttack::GameAttack(const Vec2& pos, double speed)
	: GameObject(Circle(pos, RADIUS), ObjectType::ATTACK)
	, mSpeed(speed)
	, mGoal(pos)
	, mIsEraseAble(false)
	, mAngleList(Array<double>{0, 0})
{
}


void Kokoha::GameAttack::update()
{
	for (size_t i = 0; i < mAngleList.size(); ++i)
	{
		const double goalAngle = Floor(Scene::Time() * ANGLE_SPEED[i]) * Math::HalfPi / 2;

		internalDividingPoint(mAngleList[i], goalAngle, ANGLE_RATE);
	}

	walkToGoal(mSpeed, mGoal);
}


void Kokoha::GameAttack::draw() const
{
	for (size_t i = 0; i < mAngleList.size(); ++i)
	{
		TextureAsset(U"Attack")(TEXTURE_POS[i], TEXTURE_SIZE).rotated(mAngleList[i]).drawAt(mBody.center);
	}
}


bool Kokoha::GameAttack::isEraseAble() const
{
	return mIsEraseAble;
}


void Kokoha::GameAttack::checkAnother(const GameObject& another)
{
	// 敵オブジェクトに当たった時の処理
}
