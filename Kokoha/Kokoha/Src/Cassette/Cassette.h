#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
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

		// ���ʎ���(�b) { �J�n,�I�� }
		const std::pair<double, double> TERM;

		// ����
		const std::function<void()> EFFECT;

	public:

		/// <summary>
		/// �J�Z�b�g
		/// </summary>
		/// <param name="name"  > ���O                    </param>
		/// <param name="cost"  > �R�X�g                  </param>
		/// <param name="term"  > ���ʎ���(�b){�J�n,�I��} </param>
		/// <param name="effect"> ����                    </param>
		Cassette(const String& name, int32 cost, const std::pair<double, double>& term, const std::function<void()>& effect);

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
		bool getUsed()
		{
			return mUsed;
		}

	};
}