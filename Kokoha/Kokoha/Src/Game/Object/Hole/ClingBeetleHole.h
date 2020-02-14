#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ClingBeetleHoleクラス
	プライヤーに近づき
	白い敵を生成する
	*/
	class ClingBeetleHole : public GameHole
	{
	private:

		// 目的座標
		Vec2 mGoal;

	public:

		ClingBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}