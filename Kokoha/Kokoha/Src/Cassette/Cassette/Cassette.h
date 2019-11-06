#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	CassetteEffect�N���X
	�J�Z�b�g�̌��ʂ̊Ǘ�
	�������Ԃƍs�������̂܂Ƃ�
	*/
	class CassetteEffect
	{
	public:

		// �J�n����(�b)
		const double BEGIN_SECOND;

		// ����(�J�Z�b�g�̌���)
		const std::function<void()> EFFECT_FUNCTION;

	public:

		CassetteEffect(double beginSecond, const std::function<void()>& func)
			: BEGIN_SECOND(beginSecond)
			, EFFECT_FUNCTION(func)
		{
		}

		bool operator<(const CassetteEffect& another)const
		{
			return BEGIN_SECOND < another.BEGIN_SECOND;
		}

	};

	class Cassette;
	using CassettePtr = std::shared_ptr<Cassette>;

	/*
	Cassette�N���X
	�����i�̂悤�Ȉ�������,
	�Z�b�g�A�b�v��ʂ�X�e�[�W�ň���
	*/
	class Cassette
	{
	private:

		// �g���Ă��邩
		bool mUsed;

	public:

		// ���O
		const String NAME;

		// �R�X�g
		const int32 COST;

		// �J�Z�b�g�̌���
		const CassetteEffect EFFECT;

	public:

		/// <summary>
		/// ��J�Z�b�g
		/// </summary>
		Cassette()
			: NAME(U"")
			, COST(0)
			, EFFECT(0, [](){})
		{
		}

		/// <summary>
		/// �J�Z�b�g
		/// </summary>
		/// <param name="name"  > ���O               </param>
		/// <param name="cost"  > �R�X�g             </param>
		/// <param name="term"  > ���ʂ̊J�n����(�b) </param>
		/// <param name="effect"> ����               </param>
		Cassette(const String& name, int32 cost, const CassetteEffect& cassetteEffect);

		/// <summary>
		/// �g�p�����ǂ����̐؂�ւ�
		/// </summary>
		/// <param name="used"> true �Ȃ�g�p�� , false�Ȃ疢�g�p </param>
		void setUsed(bool used)
		{
			mUsed = used;
		}

		/// <summary>
		/// �g�p����
		/// </summary>
		/// <returns> true �Ȃ�g�p�� , false�Ȃ疢�g�p </returns>
		bool getUsed()const
		{
			return mUsed;
		}

		/// <summary>
		/// ���ʂ̎擾
		/// </summary>
		/// <returns>
		/// ����
		/// </returns>
		const CassetteEffect& getEffect()const
		{
			return EFFECT;
		}

		/// <summary>
		/// �X�s�[�h�J�Z�b�g�̌��ʂ̍쐬
		/// </summary>
		/// <param name="speed"> �����̔{�� </param>
		/// <param name="term" > ���ʎ���   </param>
		static CassetteEffect&& getSpeedEffect(double speed, const std::pair<double, double>& term);

	};

}