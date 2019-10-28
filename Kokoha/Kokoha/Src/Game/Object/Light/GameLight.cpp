#include "GameLight.h"
#include "../../../MyColor.h"


namespace
{
	// îºåaÇ…ëŒÇ∑ÇÈÇ⁄Ç©ÇµÇÃäÑçá
	constexpr double BLUR_RATE = 0.4;
}


Kokoha::GameLight::GameLight(const Circle& body, double speed, double eraseSecond)
	: GameObject(body, ObjectType::LIGHT)
	, mGoal(body.center)
	, mSpeed(speed)
	, mEraseSecond(eraseSecond)
{
}


void Kokoha::GameLight::update()
{
	mEraseSecond -= Scene::DeltaTime();
	walkToGoal(mSpeed, mGoal);
}


void Kokoha::GameLight::drawLight() const
{
	mBody.drawShadow(Vec2::Zero(), mBody.r * BLUR_RATE, 0, MyWhite);
}


bool Kokoha::GameLight::isEraseAble() const
{
	return mEraseSecond < 0;
}
