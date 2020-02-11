#pragma once

#include "GameGoal.h"
#include "../Enemy/MinionEnemy.h"


namespace Kokoha
{
	/*
	LeaderGoalクラス
	プレイヤーに少しずつ近づく
	MinionEnemyをまわりに持つ
	*/
	class LeaderGoal : public GameGoal
	{
	private:

		// 手下リスト
		Array<MinionEnemy> mMinionList;

	public:

		LeaderGoal(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

		void draw() const override;

		void drawLight() const override;

	};
}