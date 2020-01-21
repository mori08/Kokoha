#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	RandomGoalクラス
	ランダムに動くゴール
	*/
	class RandomGoal : public GameGoal
	{
	public:

		RandomGoal(const Vec2& pos);

	private:

		virtual void update()override;

	};
}