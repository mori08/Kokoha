#include "GameLight.h"
#include "../../../MyColor.h"
#include "../../../MyLibrary.h"


namespace
{
	// ���a�ɑ΂���ڂ����̊���
	constexpr double BLUR_RATE = 0.4;

	// ����ύX���銄��
	constexpr double LIGHT_RATE = 0.2;

	// �폜�����̃A���t�@�l
	constexpr double ERASE_ALPHA = 0.01;
}


Kokoha::GameLight::GameLight(const Circle& body, double speed, double eraseSecond)
	: GameObject(body, ObjectType::LIGHT)
	, mGoal(body.center)
	, mSpeed(speed)
	, mEraseSecond(eraseSecond)
	, mEraseAble(false)
	, mAlpha(0)
{
}


void Kokoha::GameLight::update()
{
	// �폜�����̍X�V
	mEraseSecond -= Scene::DeltaTime();
	mEraseAble = mEraseAble || (mEraseSecond < 0);
	
	// ���邳�̕ύX
	internalDividingPoint(mAlpha, (mEraseAble ? 0.0 : 1.0), LIGHT_RATE);

	// ���W�̈ړ�
	if ((mGoal - mBody.center).length() < mSpeed)
	{
		mBody.setPos(mGoal);
	}
	else
	{
		mBody.moveBy(mSpeed * (mGoal - mBody.center).normalized());
	}
}


void Kokoha::GameLight::drawLight() const
{
	ColorF color(MyWhite);
	color.setA(mAlpha);
	mBody.drawShadow(Vec2::Zero(), mBody.r * BLUR_RATE, 0, color);
}


bool Kokoha::GameLight::isEraseAble() const
{
	return mEraseAble && mAlpha < ERASE_ALPHA;
}
