#pragma once


#include "AdventureWindow.h"
#include "CassetteView/CassetteView.h"


namespace Kokoha
{
	/*
	SetupWindow�N���X
	�����J�Z�b�g�̕ύX
	*/
	class SetupWindow : public AdventureWindow
	{
	private:

		// �{�^�����w���J�[�\��
		RectF mCursor;

		// �������Ă���J�Z�b�g�ꗗ
		CassetteView mPossessCassetteView;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
