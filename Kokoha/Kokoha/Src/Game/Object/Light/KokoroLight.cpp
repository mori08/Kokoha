#include "KokoroLight.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// ���a
	constexpr double RADIUS = 100;

	// �����̔䗦
	constexpr double RATE = 0.1 / 60.0;
}


Kokoha::KokoroLight::KokoroLight()
	: GameLight(Circle(GameManager::instance().getPlayerPos(), RADIUS), 0, Inf<double>)
{
}


void Kokoha::KokoroLight::update()
{
	mGoal = mBody.center;

	GameLight::update();

	internalDividingPoint
	(
		mBody.center,
		Cursor::PosF(),
		RATE
	);
}
