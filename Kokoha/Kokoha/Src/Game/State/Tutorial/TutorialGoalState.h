#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialGoalStateƒNƒ‰ƒX
	ƒS[ƒ‹‚ÖŒü‚©‚¤
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