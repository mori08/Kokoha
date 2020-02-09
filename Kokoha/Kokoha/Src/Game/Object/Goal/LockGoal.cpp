#include "LockGoal.h"


namespace
{
	// åÆÇÃêî
	constexpr int32 KEY_NUM = 6;
}


Kokoha::LockGoal::LockGoal(const Vec2& pos)
	: GameGoal(pos)
	, mIsOpened(false)
{
	for (int32 i = 0; i < KEY_NUM; ++i)
	{
		mKeyList.emplace_back(pos);
	}

	mSlide.start(U"lock");
}


void Kokoha::LockGoal::update()
{
	int32 checkNum = 0;

	// åÆÇÃçXêV
	for (auto& key : mKeyList)
	{
		key.update();
		if (key.isChecked()) { ++checkNum; }
	}

	// åÆÇäJÇ≠
	if (!mIsOpened && checkNum == KEY_NUM)
	{
		mIsOpened = true;
		mSlide.start(U"unlock");
	}
	

	GameGoal::update();
}


void Kokoha::LockGoal::draw() const
{
	for (const auto& key : mKeyList) { key.draw(); }

	GameGoal::draw();
}


void Kokoha::LockGoal::checkAnother(const GameObject& another)
{
	for (auto& key : mKeyList)
	{
		key.checkAnother(another);
	}

	if (mIsOpened)
	{
		GameGoal::checkAnother(another);
	}
}
