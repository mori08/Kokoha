#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*

	*/
	class GameOverState : public GameState
	{
	private:

		// �o�ߎ���
		double mTimeSecond;

		// �}�X��\������Ƃ��̃A���t�@�l
		double mSquareAlpha;

		// �J�ڐ�̃V�[��
		Optional<SceneName> mSceneName;

		// �J�[�\��
		RectF mCursor;

	public:

		GameOverState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}