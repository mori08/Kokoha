#pragma once


#include "AdventureWindow.h"
#include "../../Input/Button.h"


namespace Kokoha
{
	/*
	MenuWindow�N���X
	���j���[
	Diary,Setup,Record�̃E�B���h�E�ɑJ��
	*/
	class MenuWindow : public AdventureWindow
	{
	private:

		// �I�𒆂̃{�^��
		std::pair<Vec2, String> mSelectedButton;

		// �I�����Ă���{�^�������������`
		RectF mCursor;

	public:

		/// <summary>
		/// ���j���[�p�E�B���h�E
		/// </summary>
		MenuWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}