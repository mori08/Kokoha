#pragma once


#include "../GameState.h"


namespace Kokoha
{
	/*
	AwakeState�N���X
	Tutorial�I����̏��
	*/
	class AwakeState : public GameState
	{
	private:

		// ����
		double mTimeSecond;

		// �w�i�̃A���t�@�l
		double mBackAlpha;

	public:

		AwakeState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}