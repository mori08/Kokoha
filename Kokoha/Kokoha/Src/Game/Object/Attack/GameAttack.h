#pragma once


#include "../GameObject.h"

namespace Kokoha
{
	/*
	GameAttackクラス
	GameManagerで扱う攻撃オブジェクト
	敵オブジェクトに当たると消えます
	*/
	class GameAttack : public GameObject
	{
	private:
	
		// 移動の速さ
		const double mSpeed;

		// 目的値
		Vec2 mGoal;

		// 削除できるか
		bool mIsEraseAble;

	public:

		/// <summary>
		/// 攻撃オブジェクト
		/// </summary>
		/// <param name"pos">    生成座標 </param>
		/// <param name="speed"> 速さ     </param>
		GameAttack(const Vec2& pos, double speed);

	protected:

		virtual void update() override;

		virtual void draw() const override;

		bool isEraseAble() const override;

		virtual void checkAnother(const GameObject& another) override;

	};
}