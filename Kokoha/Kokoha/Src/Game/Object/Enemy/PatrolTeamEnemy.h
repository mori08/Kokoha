#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	PatrolTeamEnemyクラス
	近づくとチームで追いかける
	*/
	class PatrolTeamEnemy : public BlackEnemy
	{
	private:

		// プレイヤーを追いかけるとき true
		static bool sIsChasing;

		// 目的地
		Vec2 mGoal;

		// 目的地変更の時間
		double mChangeGoalSecond;

	public:

		PatrolTeamEnemy(const Vec2& pos);

	private:

		void update() override;

		void draw()const override;

		void checkAnother(const GameObject& another) override;

	};
}