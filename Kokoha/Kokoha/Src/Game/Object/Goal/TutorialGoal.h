#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	TutorialGoalクラス
	チュートリアル用ゴール
	ClearStateではなくAwakeStateに遷移
	*/
	class TutorialGoal : public GameGoal
	{
	public:

		TutorialGoal(const Vec2& pos);

	private:

		void checkAnother(const GameObject& another) override;

	};
}