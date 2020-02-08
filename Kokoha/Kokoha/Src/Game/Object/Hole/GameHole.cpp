#include "GameHole.h"
#include "../../../MyLibrary.h"


namespace
{
	// ���a
	constexpr double RADIUS = 15.0;

	// ��]���x
	constexpr std::array<double, Kokoha::GameHole::RING_NUM> ANGLE_SPEED = { 0.2,0.5 };

	// ��]�p�̕ύX�̊���
	constexpr double ANGLE_RATE = 0.01;

	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(30, 30);

	// ���ID
	constexpr Point FACE_POS(2, 0);
}


Kokoha::GameHole::GameHole(const Vec2& pos, double generateSpan)
	: GameObject(Circle(pos, RADIUS), ObjectType::HOLE)
	, mGoal(pos)
	, mGenerateSpan(generateSpan, 1.0)
{
	for (auto& angle : mRingAngleList) { angle = 0; }
}


void Kokoha::GameHole::update()
{
	for (int32 i = 0; i < RING_NUM; ++i)
	{
		const double goalAngle = Floor(Scene::Time() * ANGLE_SPEED[i]) * Math::QuarterPi;
		internalDividingPoint(mRingAngleList[i], goalAngle, ANGLE_RATE);
	}
}


void Kokoha::GameHole::draw() const
{
	for (int32 i = 0; i < RING_NUM; ++i)
	{
		TextureAsset(U"Hole")(Point(i * TEXTURE_SIZE.x, 0), TEXTURE_SIZE)
			.rotated(mRingAngleList[i])
			.drawAt(mBody.center);
	}

	TextureAsset(U"Hole")(FACE_POS * TEXTURE_SIZE, TEXTURE_SIZE).drawAt(mBody.center);
}
