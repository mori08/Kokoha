#pragma once


#include "Cassette/Cassette.h"


namespace Kokoha
{
	/*
	Equipment�N���X
	�J�Z�b�g�̑����󋵂̊Ǘ�
	���ʂ̔���
	*/
	class Equipment
	{
	private:

		// �������g��������
		double mUsedSecond;

		// ���R�X�g
		int32 mTotalCost;

		// �������Ă���J�Z�b�g�̃��X�g
		std::unordered_map<String, CassettePtr> mCassetteList;

		// �����҂��̌��ʂ̃L���[(sort�̂���list�Ŏ���)
		std::list<CassetteEffect> mEffectQueue;

	public:

		Equipment();

	public:

		// AdventureScene�Ŏg�p
		// ��

		/// <summary>
		/// �J�Z�b�g�̒ǉ�
		/// </summary>
		/// <param name="cassette"> �J�Z�b�g </param>
		void addCassette(const CassettePtr& cassette);

		/// <summary>
		/// �J�Z�b�g�̍폜
		/// </summary>
		/// <param name="name"> �J�Z�b�g�� </param>
		void removeCassette(const String& name);

		// ��
		// AdventureScene�Ŏg�p

	public:

		// GameScene�Ŏg�p
		// ��

		/// <summary>
		/// mEffectQueue�𑕔��󋵂ɍ��킹�ď�����
		/// </summary>
		void initEffect();

		/// <summary>
		/// mEffectQueue���X�V
		/// </summary>
		void updateEffect();

		// ��
		// GameScene�Ŏg�p

	};
}