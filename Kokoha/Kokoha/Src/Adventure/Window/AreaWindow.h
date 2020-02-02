#pragma once


#include "AdventureWindow.h"
#include "../../Input/ButtonManager.h"


namespace Kokoha
{
	/*
	AreaWindow�N���X
	�G���A�ړ��p�̃E�B���h�E
	*/
	class AreaWindow : public AdventureWindow
	{
	private:

		// �{�^���̃��X�g
		Array<Button> mButtonList;

		// �J�[�\��
		RectF mCursor;

	public:

		AreaWindow();

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}