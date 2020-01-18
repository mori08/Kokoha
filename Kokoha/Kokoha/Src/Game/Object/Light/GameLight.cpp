#include "GameLight.h"
#include "../../../MyColor.h"
#include "../../../MyLibrary.h"
#include "../../GameManager.h"


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
	mEquipmentId = GameManager::instance().getEquipmentId();
}


void Kokoha::GameLight::update()
{
	// �폜�����̍X�V
	mEraseSecond -= Scene::DeltaTime();
	bool isChangedEquipment = ((mEquipmentId - GameManager::instance().getEquipmentId()) != 0);
	mEraseAble = mEraseAble || (mEraseSecond < 0) || isChangedEquipment;
	
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
