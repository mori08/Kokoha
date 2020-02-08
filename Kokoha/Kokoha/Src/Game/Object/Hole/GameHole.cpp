#include "GameHole.h"
#include "../../../MyLibrary.h"


namespace
{
	// îºåa
	constexpr double RADIUS = 15.0;

	// âÒì]ë¨ìx
	constexpr std::array<double, Kokoha::GameHole::RING_NUM> ANGLE_SPEED = { 0,0 };

	// âÒì]äpÇÃïœçXÇÃäÑçá
	constexpr double ANGLE_RATE = 0.01;
}


Kokoha::GameHole::GameHole(const Vec2& pos)
	: GameObject(Circle(pos, RADIUS), ObjectType::HOLE)
	, mGoal(pos)
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
}
