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

		const Vec2 LIGHT_SIZE;

		// ����
		double mTimeSecond;

		// �w�i�̃A���t�@�l
		double mAlpha;

		// ��
		std::array<RectF, 2> mLight;

	public:

		ClearState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}