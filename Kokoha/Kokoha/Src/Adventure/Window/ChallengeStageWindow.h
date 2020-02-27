#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	ChallengeStageWindow�N���X
	�X�e�[�W�ɒ��킷�邩�m�F����E�B���h�E
	*/
	class ChallengeStageWindow : public AdventureWindow
	{
	private:

		// �X�e�[�W��
		const String mStageName;

		// �J�[�\��
		RectF mCursor;

		// �J�[�\���̈ړ���
		std::pair<Vec2, String> mSelectedButton;

		// �X�e�[�W�̃��x��
		static std::unordered_map<String, int32> sLevel;

	public:

		ChallengeStageWindow(const String& stageName);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	public:

		/// <summary>
		/// �X�e�[�W�̃��x���̐ݒ�
		/// </summary>
		static void setLevel();

	};
}