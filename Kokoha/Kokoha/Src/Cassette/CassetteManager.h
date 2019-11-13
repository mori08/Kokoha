#pragma once


#include "Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteManager�N���X
	Cassette���������Ă��邩�̊Ǘ�
	�Z�b�g�̕ύX
	*/
	class CassetteManager
	{
	private:

		// �J�Z�b�g�̏W��
		Array<CassettePtr> mCassetteList;

		// �������Ă���J�Z�b�g�̏W��
		CassettePtrSet mPossessCassette;

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

	};
}