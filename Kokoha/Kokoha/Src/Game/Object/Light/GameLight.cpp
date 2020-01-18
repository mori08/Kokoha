#include "GameLight.h"
#include "../../../MyColor.h"
#include "../../../MyLibrary.h"
#include "../../GameManager.h"


namespace
{
	// 半径に対するぼかしの割合
	constexpr double BLUR_RATE = 0.4;

	// 光を変更する割合
	constexpr double LIGHT_RATE = 0.2;

	// 削除条件のアルファ値
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
	// 削除条件の更新
	mEraseSecond -= Scene::DeltaTime();
	bool isChangedEquipment = ((mEquipmentId - GameManager::instance().getEquipmentId()) != 0);
	mEraseAble = mEraseAble || (mEraseSecond < 0) || isChangedEquipment;
	
	// 明るさの変更
	internalDividingPoint(mAlpha, (mEraseAble ? 0.0 : 1.0), LIGHT_RATE);

	// 座標の移動
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
