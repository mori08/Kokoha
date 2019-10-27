#pragma once


#include "GameEnemy.h"


namespace Kokoha
{
	/*
	WhiteEnemyクラス
	白い敵オブジェクトの基底クラス
	*/
	class WhiteEnemy : public GameEnemy
	{
	public:

		WhiteEnemy(const Vec2& pos);

	private:

		bool isEraseAble()const override;

		void checkAnother(const GameObject& type) override;

	};
}