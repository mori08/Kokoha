#include "AdventurePlayer.h"
#include "../Input/InputManager.h"
#include "../Record/RecordManager.h"


namespace
{
	// y���W
	constexpr int32 POS_Y = 362;
	// �傫��
	constexpr Size SIZE(60, 60);
	// �ړ��X�s�[�h
	constexpr double SPEED = 60;

	// �������̉摜�ԍ�
	constexpr Point MOVE_TEXTURE_POS(0, 2);

	// �����A�j���[�V����
	const Kokoha::Animation WALK_ANIM
	{
		0.3,
		Array<Point>{Point(1,2),Point(0,2)},
		true
	};

	// �����A�j���[�V����
	const Kokoha::Animation STAND_ANIM
	{
		0.0,
		Array<Point>{Point(0,2)},
		false
	};

	// �O�����A�j���[�V����
	const Kokoha::Animation FRONT_ANIM
	{
		0.0,
		Array<Point>{Point(0,0)},
		false
	};

	// ������A�j���[�V����
	const Kokoha::Animation BACK_ANIM
	{
		0.0,
		Array<Point>{Point(2,2)},
		false
	};

	// �m�F�A�C�R����\��������W�̂���
	constexpr Point CHECK_OFFSET(0, -60);
}


Kokoha::AdventurePlayer::AdventurePlayer()
	: mSlide(U"MainRobot", SIZE, MOVE_TEXTURE_POS)
	, mDirection(+1)
{
	mSlide.setAnimation(U"Walk" , WALK_ANIM);
	mSlide.setAnimation(U"Stand", STAND_ANIM);
	mSlide.setAnimation(U"Front", FRONT_ANIM);
	mSlide.setAnimation(U"Back" , BACK_ANIM);
}


void Kokoha::AdventurePlayer::set(int32 posX, int32 direction)
{
	mPosX = posX;
	if (direction * mDirection < 0)
	{
		mSlide.mirror();
		mDirection *= -1;
	}
	mCheckPos = none;
}


void Kokoha::AdventurePlayer::update(Array<AdventureObject>& objectList)
{
	walk(objectList);

	mCheckPos = check(objectList);

	RecordManager::instance().setRecord(U"PlayerPos"      , (int32)mPosX   );
	RecordManager::instance().setRecord(U"PlayerDirection", mDirection == 1);
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
		if (!object.isPassing() && object.getRegion().intersects(nextPos)) { moveAble = false; break; }
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

	// �A�j���[�V�����̕ύX
	if (direction == 0)
	{
		if (KeyS.pressed())
		{
			mSlide.startAnotherAnimation(U"Front");
		}
		else if (KeyW.pressed())
		{
			mSlide.startAnotherAnimation(U"Back");
		}
		else
		{
			mSlide.startAnotherAnimation(U"Stand");
		}
	}
	else
	{
		mSlide.startAnotherAnimation(U"Walk");
	}
	mSlide.changeTexture();
}


Optional<Point> Kokoha::AdventurePlayer::check(Array<AdventureObject>& objectList)
{
	for (auto& object : objectList)
	{
		if (object.getRegion().contains(getRegion().center()))
		{
			if (InputManager::instance().decision())
			{
				object.onClick();
			}
			return object.getRegion().center().asPoint() + CHECK_OFFSET;
		}
	}

	return none;
}
