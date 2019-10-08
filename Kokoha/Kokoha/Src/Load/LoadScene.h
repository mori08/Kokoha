#pragma once


#include "../Scene.h"
#include <thread>


namespace Kokoha
{
	/*
	LoadScene�N���X
	���Ԃ̂����鏈����ʃX���b�h�ōs���V�[��
	�����̓��e��load�֐�, �I�����̏�����complete�֐���
	�I�[�o�[���[�h���Ĕh���N���X���쐬����
	*/
	class LoadScene : public MyApp::Scene
	{
	private:

		// ���[�h���̂Ƃ� true , �I�������Ƃ� false
		bool mIsLoading;

		// ���[�h���ɕ\�����镶����
		String mText;

	protected:

		// ���[�h����X���b�h
		std::thread mLoadThread;

	public:

		/// <summary>
		/// ���[�h���s���V�[���̊��
		/// </summary>
		/// <param name="text">
		/// ���[�h���ɕ\������e�L�X�g
		/// </param>
		LoadScene(const InitData& init,const String& text = U"Loading");

		virtual ~LoadScene();

	private:

		void update() override;

		virtual void draw() const override;

		void drawFadeIn(double) const override;

		void drawFadeOut(double) const override;

	protected:

		/// <summary>
		/// mLoadThread�œ������֐�
		/// </summary>
		/// <remarks>
		/// ���[�h���̓Q�[�����I�������邱�Ƃ��ł��Ȃ��Ȃ�̂�
		/// �����I�Ȏ��ԂŏI��鏈���������Ă�������
		/// </remarks>
		virtual void load() = 0;

		/// <summary>
		/// �X���b�h�̏������I�������Ƃ��ɍs������
		/// </summary>
		/// <remarks>
		/// �K���V�[���J�ڂ��s��
		/// </remarks>
		virtual void complete() = 0;

	};

}