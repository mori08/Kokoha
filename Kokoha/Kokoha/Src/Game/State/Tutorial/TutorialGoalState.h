#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialGoalState�N���X
	�S�[���֌�����
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