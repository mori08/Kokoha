#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialGoalStateクラス
	ゴールへ向かう
	*/
	class TutorialGoalState : public TutorialState
	{
	private:

		Vec2 goalPos;

	public:

		TutorialGoalState();

	private:

		void update() override;

	};
}