#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceClingEnemyクラス
	DefenceEnemyの派生
	攻撃時はプレイヤーに近づく
	*/
	class DefenceClingEnemy : public DefenceEnemy
	{
	public:

		DefenceClingEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}