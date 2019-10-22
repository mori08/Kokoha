#pragma once


#include "Window/AdventureWindow.h"


namespace Kokoha
{
	/*
	AdventureObject�N���X
	AdventureManager�Ŏg�p����I�u�W�F�N�g
	����L�[�������ꂽ�Ƃ�
	*/
	class AdventureObject
	{
	private:

		// �摜���ƊJ���E�B���h�E�̑Ή��֌W
		static std::unordered_map<String, std::function<WindowPtr()>> sMakeWindowFuncMap;

		// �����蔻��͈̔�
		Rect mRegion;

		// �摜��
		String mTextureName;

		// �s�����x
		double mAlpha;

		// �ʉ߉\��
		const bool mIsPassing;

		// ����������ꂽ�Ƃ��̏���
		std::function<void()> mOnClick;

	public:

		/// <summary>
		/// Adventure�̃I�u�W�F�N�g
		/// </summary>
		/// <param name="pos">         ���W       </param>
		/// <param name="textureName"> �摜�̖��O </param>
		/// <param name="pass">        �ʉ߉\�� </param>
		AdventureObject(const Point& pos, const String& textureName, bool pass);

		/// <summary>
		/// �E�B���h�E���쐬����֐����}�b�v�ɓo�^
		/// </summary>
		static void registerWindow();

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="playerRegion"> �v���C���[�͈̔� </param>
		void update(const Rect& playerRegion);

		/// <summary>
		/// �`��
		/// </summary>
		/// <param name="cameraPos"> �J�����̍��W </param>
		void draw(const Point& cameraPoint)const;

		/// <summary>
		/// �͈͂̎擾
		/// </summary>
		const Rect& getRegion()const
		{
			return mRegion;
		}

		/// <summary>
		/// �ʉ߉\�� true
		/// </summary>
		bool isPassing() const
		{
			return mIsPassing;
		}

		/// <summary>
		/// ���艟���ꂽ�Ƃ��̏����̐ݒ�
		/// </summary>
		/// <param name="func"> ���� </param>
		void setOnClick(std::function<void()>& func)
		{
			mOnClick = func;
		}

	};
}