#include "AdventurePlayer.h"


namespace
{
	// y���W
	constexpr int32 POS_Y = 360;
	// �傫��
	constexpr Size SIZE(60, 60);
	// �ړ��X�s�[�h
	constexpr double SPEED = 10;

	// �������̉摜�ԍ�
	constexpr Point MOVE_TEXTURE_POS(0, 2);
}


Kokoha::AdventurePlayer::AdventurePlayer()
	: mSlide(U"MainRobot", SIZE, MOVE_TEXTURE_POS)
	, mDirection(+1)
{

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
	// �V�������W�̐���
	int32 direction = 0;
	if (KeyD.pressed()) { direction += 1; }
	if (KeyA.pressed()) { direction -= 1; }
	double movement = direction * SPEED * Scene::DeltaTime();
	Rect nextPos((int32)(mPosX + movement), POS_Y, SIZE);

	// �V�������W�̊m�F�E�J��
	bool moveAble = true;
	for (const auto& object : objectList)
	{
		if (!object.isPassing() && object.getRegion().contains(nextPos)) { moveAble = false; break; }
	}
	if (moveAble)
	{
		mPosX += movement;
	}

	// �����̕ύX
	if (direction * mDirection < 0) 
	{ 
		mSlide.mirror(); 
		mDirection *= -1;
	}

	mSlide.changeTexture();
}


void Kokoha::AdventurePlayer::draw(const Point& cameraPos)const
{
	mSlide.getTexture().draw(Point((int32)mPosX, POS_Y) + cameraPos);
}


Rect Kokoha::AdventurePlayer::getRegion() const
{
	return std::move(Rect((int32)(mPosX), POS_Y, SIZE));
}
