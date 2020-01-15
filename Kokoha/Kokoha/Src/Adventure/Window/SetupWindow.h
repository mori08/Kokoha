#pragma once


#include "AdventureWindow.h"
#include "CassetteView/PossessCassetteView.h"
#include "CassetteView/EquipmentCassetteView.h"


namespace Kokoha
{
	/*
	SetupWindow�N���X
	�����J�Z�b�g�̕ύX
	*/
	class SetupWindow : public AdventureWindow
	{
	private:

		// �{�^�����w���J�[�\�� {�J�[�\��,�ړI���W}
		std::pair<RectF, Vec2> mCursor;

		// �I�𒆂̃{�^����
		String mSelectedButtonName;

		// �������Ă���J�Z�b�g�ꗗ
		PossessCassetteView mPossessCassetteView;

		// �������Ă���J�Z�b�g�ꗗ
		EquipmentCassetteView mEquipmentCassetteView;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
