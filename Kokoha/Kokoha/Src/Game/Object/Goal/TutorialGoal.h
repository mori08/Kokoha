#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	TutorialGoal�N���X
	�`���[�g���A���p�S�[��
	ClearState�ł͂Ȃ�AwakeState�ɑJ��
	*/
	class TutorialGoal : public GameGoal
	{
	public:

		TutorialGoal(const Vec2& pos);

	private:

		void checkAnother(const GameObject& another) override;

	};
}