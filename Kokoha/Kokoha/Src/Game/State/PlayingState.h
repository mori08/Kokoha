#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	PlayingState�N���X
	�X�e�[�W��V�ԂƂ��̏��
	*/
	class PlayingState : public GameState
	{
	private:

		void update() override;

		void draw()const override;

	};
}