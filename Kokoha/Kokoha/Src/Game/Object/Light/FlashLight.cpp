#include "FlashLight.h"
#include "../../StageData/StageData.h"
#include "../../../MyLibrary.h"


namespace
{
	// ”¼Œa
	constexpr double RADIUS = 10.0;

	// íœ‚É‚©‚©‚éŠÔ
	constexpr double ERASE_SECOND = 2.3;

	// ”¼Œa‚ğ•ÏX‚·‚é”ä
	constexpr double RATE = 0.01;
}


Kokoha::FlashLight::FlashLight()
	: GameLight(Circle(Scene::CenterF(), 0), 0, ERASE_SECOND)
{
}


void Kokoha::FlashLight::update()
{
	internalDividingPoint
	(
		mBody.r,
		mEraseAble ? 0 : (RADIUS * StageData::SQUARE_SIZE),
		RATE
	);

	GameLight::update();
}
