#pragma once


#include "GameAttack.h"


namespace Kokoha
{
	/*
	ChaseEnemyAttackクラス
	白い敵オブジェクトを追う攻撃オブジェクト
	*/
	class ChaseEnemyAttack : public GameAttack
	{
	private:

		double mMinDistance;

	public:

		ChaseEnemyAttack(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another);

	};
}