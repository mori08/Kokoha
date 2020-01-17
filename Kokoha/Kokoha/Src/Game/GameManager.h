#pragma once


#include "StageData/StageData.h"
#include "Object/GameObject.h"
#include "PlayerSpeed/PlayerSpeed.h"


namespace Kokoha
{
	using GenerateGameObjectFunc = std::function<GameObjectPtr(const Vec2& pos)>;

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

		// �I�u�W�F�N�g�̃��X�g
		std::list<GameObjectPtr> mObjectList;

		// �I�u�W�F�N�g�𐶐�����֐��̘A�z�z��
		std::unordered_map<String, GenerateGameObjectFunc> mGenerateObjectMap;

		// �I�����Ă��鑕����ID
		int32 mEquipmentId;

		// �v���C���[�̑���
		PlayerSpeed mPlayerSpeed;

	private:

		GameManager();

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
		/// <param name="stageName"> �X�e�[�W�� </param>
		/// <returns>
		/// �G���[���b�Z�[�W
		/// </returns>
		Optional<String> load(const String& stageName);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

		/// <summary>
		/// �X�e�[�W�̎擾
		/// </summary>
		/// <returns>
		/// �X�e�[�W
		/// </returns>
		const StageData& getStageData()const
		{
			return mStageData;
		}

		/// <summary>
		/// �v���C���[�̑����̎擾
		/// </summary>
		/// <returns>
		/// �v���C���[�̑���
		/// </returns>
		double getPlayerSpeed()const
		{
			return mPlayerSpeed.get();
		}

		/// <summary>
		/// �v���C���[�̑����̕ύX�̐ݒ�
		/// </summary>
		/// <param name="speedRate"> �����̔{�� </param>
		/// <param name="term"     > ����       </param>
		void setSpeedChange(double speedRate, const std::pair<double, double>& term)
		{
			mPlayerSpeed.change(speedRate, term.second);
		}

	private:

		/// <summary>
		/// �I�u�W�F�N�g���쐬����֐��̓o�^
		/// </summary>
		/// <param name="name"> �I�u�W�F�N�g�̖��O </param>
		template<typename ObjectType>
		void setGenerateObjectFunc(const String& name)
		{
			mGenerateObjectMap[name] = GenerateGameObjectFunc
			(
				[](const Vec2& pos)
				{
					return std::make_unique<ObjectType>(pos);
				}
			);
		}

		/// <summary>
		/// �����J�Z�b�g�̐؂�ւ�
		/// </summary>
		void changeEquipment();

	};
}