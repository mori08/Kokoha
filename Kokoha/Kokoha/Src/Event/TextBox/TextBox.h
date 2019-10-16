#pragma once


#include "../../Slice/Linearly.h"


namespace Kokoha
{ 
	/*
	TextBox�N���X
	�e�L�X�g�E�A�C�R���̕\��
	*/
	class TextBox
	{
	private:

		// �b����̖��O
		String mSpeakerName;

		// �A�C�R���̉摜�̖��O
		String mIconName;

		// �\���ł���e�L�X�g�̒���
		Linearly<double> mDrawAbleLength;

		// �e�L�X�g
		String mText;

		// ���̃e�L�X�g���ݒ�ł��邩
		bool mIsReady;

	public:

		TextBox();

		/// <summary>
		/// ������
		/// </summary>
		void reset();

		/// <summary>
		/// �\������e�L�X�g�Ȃǂ̐ݒ�
		/// </summary>
		/// <param name="speakerName"> �b����̖��O        </param>
		/// <param name="iconName">    �A�C�R����          </param>
		/// <param name="drawSpan">    1������`�悷�鎞�� </param>
		/// <param name="text">        �e�L�X�g            </param>
		void set(const String& speakerName, const String& iconName, double drawSpan, const String& text);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

		/// <summary>
		/// �V�����e�L�X�g��ݒ�ł��邩����
		/// </summary>
		/// <returns>
		/// �\�Ȃ� true , �s�\�Ȃ� false
		/// </returns>
		bool isReady() const
		{
			return mIsReady;
		}

	};

}