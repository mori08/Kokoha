#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceGuardEnemyクラス
	DefenceEnemyの派生
	攻撃時はゴールとプレイヤーの間に入る
	*/
	class DefenceGuardEnemy : public DefenceEnemy
	{
	public:

		DefenceGuardEnemy(const Vec2& pos);

	private:

		void attack()override;

	};
}