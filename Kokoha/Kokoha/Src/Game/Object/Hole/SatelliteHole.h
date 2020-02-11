#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	SatelliteHoleクラス
	ゴールの周りで白い敵をゴールに向かって生成する
	*/
	class SatelliteHole : public GameHole
	{
	private:

		// ゴールの座標
		Vec2 mGoalPos;

		// 目的地
		Vec2 mToPos;

	public:

		SatelliteHole(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

		void changeGoal();

	};
}