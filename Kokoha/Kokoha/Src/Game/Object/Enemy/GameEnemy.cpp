#include "GameEnemy.h"


namespace
{
	// 画像のサイズ
	constexpr Size TEXTURE_SIZE(40, 40);
	// 体の画像の番号
	constexpr Point BODY_POS(0, 0);
	// 顔の画像の番号
	constexpr Point FACE_POS(0, 1);

	// 体のアニメーション
	const Kokoha::Animation BODY_ANIMATION
	(
		1.0,
		Array<Point>{Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0)},
		true
	);
	// 顔のアニメーション
	const Kokoha::Animation FACE_ANIMATION
	(
		5.0,
		Array<Point>{Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 1), Point(0, 1), Point(0, 1), Point(0, 1)},
		true
	);
}


Kokoha::GameEnemy::GameEnemy(const Vec2& pos, const ObjectType& type, const String& textureName)
	: GameObject(pos, type)
	, mBodySlide(textureName, TEXTURE_SIZE, BODY_POS)
	, mFaceSlide(textureName, TEXTURE_SIZE, FACE_POS)
{
	mBodySlide.setAnimation(U"anim", BODY_ANIMATION); mBodySlide.start(U"anim");
	mFaceSlide.setAnimation(U"anim", FACE_ANIMATION); mFaceSlide.start(U"anim");
}


void Kokoha::GameEnemy::update()
{
	mBodySlide.changeTexture();
	mFaceSlide.changeTexture();
}


void Kokoha::GameEnemy::draw() const
{
	mBodySlide.getTexture().drawAt(mPos);
	mFaceSlide.getTexture().drawAt(mPos);
}

