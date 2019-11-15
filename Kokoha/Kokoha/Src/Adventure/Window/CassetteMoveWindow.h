#pragma once


#include "AdventureWindow.h"
#include "../../Cassette/Cassette/Cassette.h"
#include "../../Input/Button.h"


namespace Kokoha
{
	/*
	CassetteMoveWindow�N���X
	�J�Z�b�g�𓮂����E�B���h�E
	�J�Z�b�g�̏�Ԃɂ���đ��삪�قȂ�
	*/
	class CassetteMoveWindow : public AdventureWindow
	{
	private:

		// �J�Z�b�g�̃|�C���^
		CassettePtr mCassettePtr;

		// �{�^���̃��X�g
		Array<Button> mButtonList;

		// �I�����Ă��鑕���̔ԍ�
		const int32 mSelectedEquipmentId;

		// �J�[�\��
		RectF mCursor;

		// �I�����Ă���{�^��
		std::pair<Vec2, String> mSelectedButton;

	public:

		/// <summary>
		/// �J�Z�b�g���ړ�������E�B���h�E
		/// </summary>
		/// <param name="cassette"> �J�Z�b�g               </param>
		/// <param name="pos"     > �\�����W               </param>
		/// <param name="selected"> �I�����Ă��鑕���̔ԍ� </param>
		CassetteMoveWindow(const CassettePtr& cassette, const Point& pos, int32 selected);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}