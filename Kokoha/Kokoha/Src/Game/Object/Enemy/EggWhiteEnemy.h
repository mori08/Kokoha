#pragma once


#include "WhiteEnemy.h"


namespace Kokoha
{
	/*
	EggWhiteEnemyクラス
	ランダムな方向に少しだけ動く
	*/
	class EggWhiteEnemy : public WhiteEnemy
	{
	private:

		// 角度
		const double mAngle;

	public:

		EggWhiteEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}