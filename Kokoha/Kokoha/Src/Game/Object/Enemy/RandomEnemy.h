#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	RandomEnemyクラス
	ランダムな座標を設定して移動する
	*/
	class RandomEnemy : public BlackEnemy
	{
	private:

		// 目的地
		Vec2 mGoal;

	public:

		RandomEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}