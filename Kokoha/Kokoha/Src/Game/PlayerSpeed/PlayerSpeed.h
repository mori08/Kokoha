#pragma once


#include <queue>


namespace Kokoha
{
	/*
	PlayerSpeed�N���X
	�v���C���[�̑����̔{���̊Ǘ�
	*/
	class PlayerSpeed
	{
	private:

		using ChangeSpeed = std::pair<double, double>;

	private:

		// ����(�b)
		double mTime;

		// �����̔{��
		double mSpeed;

		// �����̕ύX�ɂ��ẴL���[ { ����,�{�� }
		std::priority_queue<ChangeSpeed, std::vector<ChangeSpeed>, std::greater<ChangeSpeed>> mChangeSpeedQueue;

	public:

		PlayerSpeed()
			: mTime(0)
			, mSpeed(0)
		{
		}

		/// <summary>
		/// ������
		/// </summary>
		void init();

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �����̔{���̎擾
		/// </summary>
		/// <returns>
		/// �����̔{��
		/// </returns>
		double get()const
		{
			return mSpeed;
		}

		/// <summary>
		/// �����̕ύX�̐ݒ�
		/// </summary>
		/// <param name="speedRate"> �����̔{�� </param>
		/// <param name="endTime"  > �I������   </param>
		void change(double speedRate, double endTime);

	};
}