#pragma once


#include "AdventurePlayer.h"
#include "Window/AdventureWindow.h"
#include "../Scene.h"


namespace Kokoha
{
	/*
	AdventureManager�N���X
	CSV�t�@�C�����畔���f�[�^��ǂݍ���
	AdventureObject, Window�̊Ǘ�
	*/
	class AdventureManager
	{
	private:

		// �v���C���[
		AdventurePlayer mPlayer;

		// �����̕�
		int32 mRoomWidth;

		// �I�u�W�F�N�g�̃��X�g
		Array<AdventureObject> mObjectList;

		// �J�������W
		Point mCameraPos;

		// �E�B���h�E
		std::list<WindowPtr> mWindowList;

		// �V�[���J�ڐ�
		Optional<SceneName> mSceneName;

	private:

		AdventureManager();

		AdventureManager(const AdventureManager&)            = default;
		AdventureManager& operator=(const AdventureManager&) = default;
		AdventureManager(AdventureManager&&)                 = default;
		AdventureManager& operator=(AdventureManager&&)      = default;

	public:

		static AdventureManager& instance()
		{
			static AdventureManager adventureManager;
			return adventureManager;
		}

		/// <summary>
		/// �����̃��[�h
		/// </summary>
		/// <param name="fileName"> �t�@�C���� </param> 
		Optional<String> load(const String& fileName);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw()const;

	public:

		/// <summary>
		/// �E�B���h�E���J��
		/// </summary>
		/// <param name="window"> �J���E�B���h�E </param>
		void openWindow(WindowPtr&& window)
		{
			mWindowList.emplace_back(std::move(window));
			mWindowList.back()->select();
		}

		/// <summary>
		/// ��ԏ�̃E�B���h�E�����
		/// </summary>
		void closeWindow();

		/// <summary>
		/// �V�[���J�ڐ�̐ݒ�
		/// </summary>
		/// <param name="sceneName"> �V�[���� </param>
		void setSceneName(const SceneName& sceneName)
		{
			mSceneName = sceneName;
		}

		/// <summary>
		/// �V�[���J�ڐ�̎擾
		/// </summary>
		/// <returns> �V�[���� </returns>
		const Optional<SceneName>& getSceneName() const
		{
			return mSceneName;
		}

	private:

		/// <summary>
		/// �J�������W�̕ύX
		/// </summary>
		void changeCameraPos();

	};
}