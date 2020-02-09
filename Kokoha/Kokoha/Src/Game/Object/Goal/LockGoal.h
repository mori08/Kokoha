#pragma once


#include "GameGoal.h"
#include "Key/GameGoalKey.h"


namespace Kokoha
{
	/*
	LockGoalクラス
	鍵のかかったゴール
	GameGoalKeyを所持する
	*/
	class LockGoal : public GameGoal
	{
	private:

		// 鍵オブジェクトのリスト
		Array<GameGoalKey> mKeyList;

		// 鍵がかかっているか
		bool mIsOpened;

	public:

		LockGoal(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void checkAnother(const GameObject& another) override;

	};
}