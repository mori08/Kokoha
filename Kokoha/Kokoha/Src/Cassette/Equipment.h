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

		const int32 mCassetteState;

		// �������Ă���J�Z�b�g�̃��X�g
		CassettePtrSet mCassetteList;

		// �����҂��̌��ʂ̃L���[(sort�̂���list�Ŏ���)
		std::list<CassetteEffect> mEffectQueue;

	public:

		/// <summary>
		/// ����
		/// </summary>
		/// <param name="state"> �J�Z�b�g�ɐݒ肷���� </param>
		Equipment(int32 state);

	public:

		// AdventureScene�Ŏg�p
		// ��

		/// <summary>
		/// �S�č폜
		/// </summary>
		/// <remarks>
		/// ���R�[�h�̓ǂݍ��ݎ��ȊO�Ŏg��Ȃ�
		/// </remarks>
		void clearCassette();

		/// <summary>
		/// �J�Z�b�g�̒ǉ�
		/// </summary>
		/// <param name="cassette"> �J�Z�b�g </param>
		void addCassette(const CassettePtr& cassette);

		/// <summary>
		/// �J�Z�b�g�̍폜
		/// </summary>
		/// <param name="cassette"> �J�Z�b�g </param>
		void removeCassette(const CassettePtr& cassette);

		/// <summary>
		/// �����J�Z�b�g�̃��X�g�̎擾
		/// </summary>
		const CassettePtrSet& getCassetteList() const
		{
			return mCassetteList;
		}

		/// <summary>
		/// �J�Z�b�g�̏��
		/// </summary>
		int32 getCassetteState()const
		{
			return mCassetteState;
		}

		/// <summary>
		/// �J�Z�b�g��ǉ��ł��邩������
		/// </summary>
		/// <param name="cassette"> �ǉ��������J�Z�b�g </param>
		bool isAddAbleCassette(const CassettePtr& cassette) const;

		/// <summary>
		/// �g�p���Ă���R�X�g���擾
		/// </summary>
		const int32& getTotalCost() const
		{
			return mTotalCost;
		}

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