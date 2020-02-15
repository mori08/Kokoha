#pragma once


#include "GameGoal.h"
#include "Key/GameGoalKey.h"
#include "../Enemy/DefenceEnemy.h"


namespace Kokoha
{
	/*
	LastGoalクラス
	鍵を一つずつ出す
	周りを敵が守り，鍵が開けられるたび開放する
	*/
	class LastGoal : public GameGoal
	{
	private:

		// 守りの敵
		Array<std::unique_ptr<DefenceEnemy>> mDefenceEnemyList;

		// 鍵オブジェクトのリスト
		std::list<GameGoalKey> mKeyList;

		// 鍵がかかっているか
		bool mIsOpened;

	public:

		LastGoal(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void drawLight() const override;

		void checkAnother(const GameObject& another) override;

	};

}
