#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	PauseState�N���X
	�ꎞ��~�̏��
	�Â���E���Ȃ����E������߂� �̑I��
	*/

	class PauseState : public GameState
	{
	private:

		// �|�[�Y�O�̏��
		std::unique_ptr<GameState> mPreState;

		// �V�[������opt, �J�ڂ����Ȃ��Ƃ� none
		Optional<SceneName> mSceneName;

		// �J�[�\��
		RectF mCursor;

	public:

		PauseState(std::unique_ptr<GameState> preState);

	private:

		void update();

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const;

	};
}