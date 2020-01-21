#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	RunAwayGoalクラス
	プレイヤーから逃げるゴール
	*/
	class RunAwayGoal : public GameGoal
	{
	private:

		// 目的地を変更する時間
		double mChangeGoalSecond;

	public:

		/// <summary>
		/// プレイヤーから逃げるゴール
		/// </summary>
		/// <param name="pos"> 生成座標 </param>
		RunAwayGoal(const Vec2& pos);

	private:

		void update()override;

		/// <summary>
		/// 評価値の取得
		/// </summary>
		/// <param name="pos"> 評価したい座標 </param>
		double getDistancePoint(const Vec2& pos);
	};
}