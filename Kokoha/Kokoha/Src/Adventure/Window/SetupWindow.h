#pragma once


#include "AdventureWindow.h"
#include "CassetteView/PossessCassetteView.h"


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

		// �I�𒆂̃{�^����
		String mSelectedButtonName;

		// �������Ă���J�Z�b�g�ꗗ
		PossessCassetteView mPossessCassetteView;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
