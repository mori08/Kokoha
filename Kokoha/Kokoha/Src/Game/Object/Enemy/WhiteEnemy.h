#pragma once


#include "GameEnemy.h"


namespace Kokoha
{
	/*
	WhiteEnemyクラス
	白い敵オブジェクトの基底クラス
	攻撃に当たると消える
	*/
	class WhiteEnemy : public GameEnemy
	{
	public:

		WhiteEnemy(const Vec2& pos);

	private:

		bool isEraseAble()const override;

		void checkAnother(const GameObject& another) override;

	};
}