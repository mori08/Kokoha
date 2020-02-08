#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	RandomHoleクラス
	ランダムな方向に敵を生成する
	*/
	class RandomHole : public GameHole
	{
	private:

		// 敵を生成する角度
		double mAngle;

	public:

		RandomHole(const Vec2& pos);

	private:

		void update() override;

	};
}