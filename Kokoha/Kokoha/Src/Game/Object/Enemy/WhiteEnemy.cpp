#include "WhiteEnemy.h"


namespace
{
	// �폜���Ԃ̏�����
	constexpr double INIT_ERASE_SECOND = 5.0;

	// �A���t�@�l��ύX���鎞��
	constexpr double CHANGE_ALPHA_SECOND = 0.5;
}


Kokoha::WhiteEnemy::WhiteEnemy(const Vec2& pos)
	: GameEnemy(pos, ObjectType::WHITE_ENEMY, U"WhiteEnemy")
	, mEraseSecond(INIT_ERASE_SECOND)
	, mAlpha(CHANGE_ALPHA_SECOND, 1, -1)
	, mEraseAble(false)
{
}


void Kokoha::WhiteEnemy::update()
{
	mEraseSecond -= Scene::DeltaTime();

	if (mEraseSecond < 0)
	{
		mEraseAble = mAlpha.update();
	}

	GameEnemy::update();
}


bool Kokoha::WhiteEnemy::isEraseAble() const
{
	return mEraseAble;
}


void Kokoha::WhiteEnemy::checkAnother(const GameObject& another)
{
	GameEnemy::checkAnother(another);
}


void Kokoha::WhiteEnemy::draw() const
{
	drawChangeAlpha(mAlpha.getValue());
}
