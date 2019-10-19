#include "AdventurePlayer.h"


namespace
{
	// y座標
	constexpr int32 POS_Y = 360;
	// 大きさ
	constexpr Size SIZE(60, 60);
	// 移動スピード
	constexpr double SPEED = 10;
}


void Kokoha::AdventurePlayer::update(const Array<AdventureObject>& objectList)
{
	// 新しい座標の生成
	int32 direction = 0;
	if (KeyD.pressed()) { direction += 1; }
	if (KeyA.pressed()) { direction -= 1; }
	double movement = direction * SPEED * Scene::DeltaTime();
	Rect nextPos((int32)(mPosX + movement), POS_Y, SIZE);

	// 新しい座標の確認・遷移
	bool moveAble = true;
	for (const auto& object : objectList)
	{
		if (!object.isPassing() && object.getRegion().contains(nextPos)) { moveAble = false; break; }
	}
	if (moveAble)
	{
		mPosX += movement;
	}

	// 向きの変更
	if (direction * mDirection < 0) { mSlide.mirror(); }
	if (direction != 0) { mDirection = direction; }	

	mSlide.changeTexture();
}


void Kokoha::AdventurePlayer::draw(const Point& cameraPos)
{
	mSlide.getTexture().draw(Point((int32)mPosX, POS_Y) + cameraPos);
}


Rect Kokoha::AdventurePlayer::getRegion() const
{
	return Rect((int32)(mPosX), POS_Y, SIZE);
}
