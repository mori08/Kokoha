#pragma once


#include "GameEnemy.h"
#include "../../../Slice/Linearly.h"


namespace Kokoha
{
	/*
	WhiteEnemyクラス
	白い敵オブジェクトの基底クラス
	攻撃に当たると消える
	*/
	class WhiteEnemy : public GameEnemy
	{
	private:

		// 削除時間
		double mEraseSecond;

		// アルファ値
		Linearly<double> mAlpha;

		// 削除条件
		bool mEraseAble;

	public:

		WhiteEnemy(const Vec2& pos);

	private:

		virtual void update() override;

		bool isEraseAble()const override;

		virtual void checkAnother(const GameObject& another) override;

		void draw() const override;

	};
}