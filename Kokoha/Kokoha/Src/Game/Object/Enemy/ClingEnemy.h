#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	ClingEnemyクラス
	プレイヤーの近くに移動する敵
	*/
	class ClingEnemy : public BlackEnemy
	{
	private:

		// ゴール
		Vec2 mGoal;

	public:

		ClingEnemy(const Vec2& pos);

	private:

		void update();

	};
}