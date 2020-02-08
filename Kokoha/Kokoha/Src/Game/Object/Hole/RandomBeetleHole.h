#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	RandomBeetleHoleクラス
	目的地に移動し続け，EggWhiteEnemeyを生成する
	*/
	class RandomBeetleHole : public GameHole
	{
	protected:

		// 目的座標
		Vec2 mGoal;

	public:

		RandomBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}