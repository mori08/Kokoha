#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	DefenceEnemyクラス
	LastGoalを守る敵
	*/
	class DefenceEnemy : public BlackEnemy
	{
	private:

		// ゴールの周りをまわっているとき true
		bool mDefenceMode;

	protected:

		// ゴールの座標
		Vec2 mGoalPos;

		// 目的地
		Vec2 mToPos;

	public:

		DefenceEnemy(const Vec2& pos);

	public:

		void update() override;

		void draw() const override { BlackEnemy::draw(); }

		void drawLight() const override { BlackEnemy::drawLight(); }

		void checkAnother(const GameObject& another) override;

	public:

		/// <summary>
		/// 目的地の設定
		/// </summary>
		/// <param name="pos"> 座標 </param>
		void setToPos(const Vec2& pos)
		{
			mToPos = pos;
		}

		/// <summary>
		/// ゴールの周りをまわるのを中止
		/// </summary>
		void offDefenceMode()
		{
			mDefenceMode = false;
		}

		/// <summary>
		/// 攻撃用の目的地の設定
		/// </summary>
		virtual void attack() = 0;

	};
}