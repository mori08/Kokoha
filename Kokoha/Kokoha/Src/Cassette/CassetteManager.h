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

		// �J�Z�b�g�̃��X�g
		Array<CassettePtr> mCassetteList;

		// �����ύX�ɂ��ẴL���[ { ����, �����̔{�� }
		std::list<std::pair<double, double>> mChangeSpeedQueue;

	private:

		CassetteManager();

		CassetteManager(const CassetteManager&)            = default;
		CassetteManager& operator=(const CassetteManager&) = default;
		CassetteManager(CassetteManager&&)                 = default;
		CassetteManager& operator=(CassetteManager&&)      = default;

	public:

		static CassetteManager& instance()
		{
			static CassetteManager cassetteManager;
			return cassetteManager;
		}

	};
}