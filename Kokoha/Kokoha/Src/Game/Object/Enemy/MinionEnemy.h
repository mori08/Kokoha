#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	MinionEnemyクラス
	Leaderクラスの周りをまわる
	プレイヤーが近いと追いかける
	*/
	class MinionEnemy : public BlackEnemy
	{
	private:

		// ゴールの座標
		Vec2 mGoal;

		// ゴールとなす角度
		double mAngle;

	public:

		MinionEnemy(const Vec2& pos, double angle);

		void update() override;

		void checkAnother(const GameObject& another) override
		{
			BlackEnemy::checkAnother(another);
		}

		void draw() const override
		{
			BlackEnemy::draw();
		}

		void drawLight() const override
		{
			BlackEnemy::drawLight();
		}

		/// <summary>
		/// ゴールの座標の取得
		/// </summary>
		/// <param name="pos"> ゴールの座標 </param>
		void setGoalPos(const Vec2& pos)
		{
			mGoal = pos;
		}

	};
}