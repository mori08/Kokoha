#pragma once


#include "Cassette/Cassette.h"
#include "Equipment.h"


namespace Kokoha
{
	/*
	CassetteManager�N���X
	Cassette���������Ă��邩�̊Ǘ�
	�Z�b�g�̕ύX
	*/
	class CassetteManager
	{
	public:

		// �����J�Z�b�g�̃Z�b�g��
		static constexpr int32 EQUIPMENT_NUM = 2;

	private:

		// �J�Z�b�g�̏W��
		Array<CassettePtr> mCassetteList;

		// �������Ă���J�Z�b�g�̏W��
		CassettePtrSet mPossessCassette;

		// �����J�Z�b�g
		std::array<Equipment, EQUIPMENT_NUM> mEquipment;

		// �����ύX�ɂ��ẴL���[ { ����, �����̔{�� }
		std::list<std::pair<double, double>> mChangeSpeedQueue;

	private:

		CassetteManager();

		CassetteManager(const CassetteManager&)            = default;
		CassetteManager& operator=(const CassetteManager&) = default;
		CassetteManager(CassetteManager&&)                 = default;
		CassetteManager& operator=(CassetteManager&&)      = default;

	public:

		/// <summary>
		/// �V���O���g���̃C���X�^���X�̎擾
		/// </summary>
		static CassetteManager& instance()
		{
			static CassetteManager cassetteManager;
			return cassetteManager;
		}

	public:

		/// <summary>
		/// �����J�Z�b�g�̃��X�g���擾
		/// </summary>
		/// <returns>
		/// �����J�Z�b�g�̃��X�g
		/// </returns>
		const CassettePtrSet& getPossessCassette()const
		{
			return mPossessCassette;
		}

		/// <summary>
		/// �����J�Z�b�g�̊Ǘ��N���X�̎擾
		/// </summary>
		/// <param name="id"> �����Ȃ瑕��A , ��Ȃ瑕��B </param>
		/// <returns>
		/// �����J�Z�b�g
		/// </param>
		Equipment& getEquipment(size_t id)
		{
			return mEquipment[id % EQUIPMENT_NUM];
		}

	};
}