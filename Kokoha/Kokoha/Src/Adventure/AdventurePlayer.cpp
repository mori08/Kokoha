#include "AdventurePlayer.h"


namespace
{
	// y座標
	constexpr int32 POS_Y = 362;
	// 大きさ
	constexpr Size SIZE(60, 60);
	// 移動スピード
	constexpr double SPEED = 60;

	// 横向きの画像番号
	constexpr Point MOVE_TEXTURE_POS(0, 2);

	// 歩きアニメーション
	const Kokoha::Animation WALK_ANIM
	{
		0.5,
		Array<Point>{Point(1,2),Point(0,2)},
		true
	};

	// 立ちアニメーション
	const Kokoha::Animation STAND_ANIM
	{
		0.0,
		Array<Point>{Point(0,2)},
		false
	};

	// 確認アイコンを表示する座標のずれ
	constexpr Point CHECK_OFFSET(0, -60);
}


Kokoha::AdventurePlayer::AdventurePlayer()
	: mSlide(U"MainRobot", SIZE, MOVE_TEXTURE_POS)
	, mDirection(+1)
{
	mSlide.setAnimation(U"Walk" , WALK_ANIM);
	mSlide.setAnimation(U"Stand", STAND_ANIM);
}


void Kokoha::AdventurePlayer::set(int32 posX, int32 direction)
{
	mPosX = posX;
	if (direction * mDirection < 0)
	{
		mSlide.mirror();
		mDirection *= -1;
	}
}


void Kokoha::AdventurePlayer::update(const Array<AdventureObject>& objectList)
{
	walk(objectList);

	mCheckPos = check(objectList);
}


void Kokoha::AdventurePlayer::draw(const Point& cameraPos)const
{
	mSlide.getTexture().draw(Point((int32)mPosX, POS_Y) - cameraPos);
	
	if (mCheckPos)
	{
		TextureAsset(U"CheckIcon").drawAt(mCheckPos.value() - cameraPos, AlphaF(Abs(Sin(Scene::Time()))));
	}
}


Rect Kokoha::AdventurePlayer::getRegion() const
{
	return std::move(Rect((int32)(mPosX), POS_Y, SIZE));
}


void Kokoha::AdventurePlayer::walk(const Array<AdventureObject>& objectList)
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
		if (!object.isPassing() && object.getRegion().intersects(nextPos)) { moveAble = false; break; }
	}
	if (moveAble)
	{
		mPosX += movement;
	}

	// 向きの変更
	if (direction * mDirection < 0)
	{
		mSlide.mirror();
		mDirection *= -1;
	}

	// アニメーションの変更
	if (direction == 0)
	{
		mSlide.startAnotherAnimation(U"Stand");
	}
	else
	{
		mSlide.startAnotherAnimation(U"Walk");
	}
	mSlide.changeTexture();
}


Optional<Point> Kokoha::AdventurePlayer::check(const Array<AdventureObject>& objectList)
{
	for (const auto& object : objectList)
	{
		if (object.getRegion().intersects(getRegion()))
		{
			return object.getRegion().center().asPoint() + CHECK_OFFSET;
		}
	}

	return none;
}
