#include "GameEnemy.h"


namespace
{
	// �����蔻��̔��a
	constexpr double BODY_RADIUS = 15.0;

	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(40, 40);
	// �̂̉摜�̔ԍ�
	constexpr Point BODY_POS(0, 0);
	// ��̉摜�̔ԍ�
	constexpr Point FACE_POS(0, 1);

	// �̂̃A�j���[�V����
	const Kokoha::Animation BODY_ANIMATION
	(
		0.5,
		Array<Point>{Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0)},
		true
	);
	// ��̃A�j���[�V����
	const Kokoha::Animation FACE_ANIMATION
	(
		3.0,
		Array<Point>{Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 1), Point(0, 1), Point(0, 1), Point(0, 1)},
		true
	);
}


Kokoha::GameEnemy::GameEnemy(const Vec2& pos, const ObjectType& type, const String& textureName)
	: GameObject(Circle(pos,BODY_RADIUS), type)
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
	mBodySlide.getTexture().drawAt(mBody.center);
	mFaceSlide.getTexture().drawAt(mBody.center);
}

