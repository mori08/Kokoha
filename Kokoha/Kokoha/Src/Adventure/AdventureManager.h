#pragma once


#include "AdventurePlayer.h"


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

	private:

		/// <summary>
		/// �J�������W�̕ύX
		/// </summary>
		void changeCameraPos();

	};
}