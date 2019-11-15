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

		// �I�����Ă��鑕���̔ԍ�
		int32 mSelectedEquipmentId;

		// �{�^�����w���J�[�\��
		RectF mCursor;

		// �������Ă���J�Z�b�g�ꗗ
		CassetteView mPossessCassetteView;

		// �������Ă���J�Z�b�g�ꗗ
		CassetteView mEquipmentCassetteView;

		// �I�𒆂̃{�^��
		String mSelectedButtonName;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
