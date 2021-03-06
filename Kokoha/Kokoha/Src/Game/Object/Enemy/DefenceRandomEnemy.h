#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceRandomEnemyクラス
	DefenceEnemyの派生
	攻撃時はランダムに動く
	*/
	class DefenceRandomEnemy : public DefenceEnemy
	{
	public:

		DefenceRandomEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}