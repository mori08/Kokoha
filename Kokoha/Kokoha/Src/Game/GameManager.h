#pragma once


#include "StageData/StageData.h"


namespace Kokoha
{
	/*
	GameManager�N���X
	CSV�t�@�C������Q�[���f�[�^��ǂݍ���
	GameObject�EStageData�̊Ǘ�
	*/
	class GameManager
	{
	private:

		// �X�e�[�W
		StageData mStageData;

	private:

		GameManager()
		{

		}

		GameManager(const GameManager &)             = default;
		GameManager & operator=(const GameManager &) = default;
		GameManager(GameManager &&)                  = default;
		GameManager & operator=(GameManager &&)      = default;

	public:

		/// <summary>
		/// �V���O���g���Ƃ��ĊǗ����Ă���GameManager�̃C���X�^���X�̎擾
		/// </summary>
		/// <returns> �V���O���g�� </returns>
		static GameManager& instance()
		{
			static GameManager gameManager;
			return gameManager;
		}

		/// <summary>
		/// ������
		/// </summary>
		void init();

		/// <summary>
		/// �Q�[���f�[�^���L�q����csv�t�@�C���̓ǂݍ���
		/// </summary>
		/// <param name="fileName"> csv�t�@�C���̃t�@�C���� </param>
		/// <returns>
		/// �G���[���b�Z�[�W
		/// </returns>
		Optional<String> load(const String& fileName);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

	};
}