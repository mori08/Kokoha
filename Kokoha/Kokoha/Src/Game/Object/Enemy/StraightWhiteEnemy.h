#pragma once


#include "WhiteEnemy.h"


namespace Kokoha
{
	/*
	StraightWhiteEnemyクラス
	直進する白い敵
	コンストラクタで方向を指定
	*/
	class StraightWhiteEnemy : public WhiteEnemy
	{
	private:

		// 移動ベクトル
		Vec2 mMovement;

	public:

		/// <summary>
		/// 直進する白い敵
		/// </summary>
		/// <param name="pos"> 生成座標 </param>
		/// <param name="movement"> 移動量 </param>
		StraightWhiteEnemy(const Vec2& pos, const Vec2& movement);

	private:

		void update() override;

	};
}