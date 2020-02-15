#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceChaseEnemyクラス
	DefenceEnemyの派生
	攻撃時はプレイヤーを追跡する
	*/
	class DefenceChaseEnemy : public DefenceEnemy
	{
	public:

		DefenceChaseEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}