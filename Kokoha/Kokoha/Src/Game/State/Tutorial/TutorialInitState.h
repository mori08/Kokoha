#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialInitState�N���X
	�`���[�g���A���J�n�̏��
	*/
	class TutorialInitState : public TutorialState
	{
	public:

		TutorialInitState();

	private:

		void update() override;

	};
}