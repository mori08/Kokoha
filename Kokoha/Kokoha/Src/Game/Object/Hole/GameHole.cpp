#include "GameHole.h"
#include "../../../MyLibrary.h"


namespace
{
	// 半径
	constexpr double RADIUS = 15.0;

	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(20, 20);

	// 顔のID
	constexpr Point FACE_POS(2, 0);

	// まばたきのアニメーション
	const Kokoha::Animation EYE_ANIM
	(
		3.0,
		Array<Point>{Point(1, 0), Point(2, 0), Point(3, 0), Point(2, 0), Point(1, 0), Point(1, 0), Point(1, 0), Point(1, 0), Point(1, 0), Point(1, 0)},
		true
	);
}


Kokoha::GameHole::GameHole(const Vec2& pos, double generateSpan)
	: GameObject(Circle(pos, RADIUS), ObjectType::HOLE)
	, mGenerateSpan(generateSpan, 1.0)
	, mSlide(U"Hole", TEXTURE_SIZE, Point(1, 0))
{
	mSlide.setAnimation(U"anim", EYE_ANIM);
}


void Kokoha::GameHole::update()
{
	mSlide.changeTexture();
}


void Kokoha::GameHole::draw() const
{
	TextureAsset(U"Hole")(Point::Zero(), TEXTURE_SIZE).drawAt(mBody.center);
	mSlide.getTexture().drawAt(mBody.center);
}
