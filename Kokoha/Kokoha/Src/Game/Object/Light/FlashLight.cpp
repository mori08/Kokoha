#include "FlashLight.h"
#include "../../StageData/StageData.h"
#include "../../../MyLibrary.h"


namespace
{
	// ���a
	constexpr double RADIUS = 10.0;

	// �폜�ɂ����鎞��
	constexpr double ERASE_SECOND = 2.3;

	// ���a��ύX�����
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
