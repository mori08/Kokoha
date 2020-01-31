#pragma once


#include "GameEnemy.h"


namespace Kokoha
{
	/*
	BlackEnemyクラス
	黒い敵オブジェクトの基底クラス
	*/
	class BlackEnemy : public GameEnemy
	{
	public:

		BlackEnemy(const Vec2& pos);

	private:

		bool isEraseAble()const override
		{
			return false;
		}

		void checkAnother(const GameObject& another)
		{
			GameEnemy::checkAnother(another);
		}

	};
}