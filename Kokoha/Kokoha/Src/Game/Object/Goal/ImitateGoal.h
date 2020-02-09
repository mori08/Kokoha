#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	ImitateGoalクラス
	プライヤーの動きをまねるゴール
	WASDキーで移送
	*/
	class ImitateGoal : public GameGoal
	{
	public:

		ImitateGoal(const Vec2& pos);

	private:

		void update() override;

	};
}