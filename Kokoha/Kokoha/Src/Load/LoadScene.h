#pragma once


# define SIV3D_CONCURRENT
# include <Siv3D.hpp>
# include "../Scene.h"


namespace Kokoha
{
	// �G���[���b�Z�[�W
	using ErrorMessage = Optional<String>;


	/*
	LoadScene�N���X
	���Ԃ̂����鏈����ʃX���b�h�ōs���V�[��
	�����̓��e��load�֐�, �I�����̏�����complete�֐���
	�I�[�o�[���[�h���Ĕh���N���X���쐬����
	*/
	class LoadScene : public MyApp::Scene
	{
	private:

		// �~���[�e�b�N�X
		std::mutex mtx;

		// ���[�h���̂Ƃ� true , �I�������Ƃ� false
		bool mIsLoading;

		// ���[�h���ɕ\�����镶����
		String mText;

		// ���[�h����X���b�h
		std::thread mLoadThread;

		// �G���[���b�Z�[�W
		ErrorMessage mError;

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
		/// �����I�Ȏ��ԂŏI��鏈��������.
		/// </remarks>
		virtual ErrorMessage load() = 0;

		/// <summary>
		/// �X���b�h�̏������I�������Ƃ��ɍs������
		/// </summary>
		/// <returns>
		/// �J�ڐ�̃V�[��
		/// </returns>
		virtual SceneName complete() = 0;

	};

}