#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialMoveState�N���X
	�ړ����@�̐���
	*/
	class TutorialMoveState : public TutorialState
	{
	private:

		// �v���C���[�̍��W
		Vec2 mPlayerPos;

		// �ړ�����
		double mMoveDistance;

	public:

		TutorialMoveState();

	private:

		void update() override;

		void draw() const override;

	};
}