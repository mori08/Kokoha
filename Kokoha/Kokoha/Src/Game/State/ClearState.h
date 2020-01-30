#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	ClearState�N���X
	�v���C���[���S�[�������Ƃ��ɑJ�ڂ�����
	*/
	class ClearState : public GameState
	{
	private:

		// ����
		double mTimeSecond;

		// �w�i�̃A���t�@�l
		double mBackAlpha;

		// ���̃A���t�@�l
		double mLightAlpha;

		// ���S�ƌ��Ƃ̋���
		double mRadius;

	public:

		ClearState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}