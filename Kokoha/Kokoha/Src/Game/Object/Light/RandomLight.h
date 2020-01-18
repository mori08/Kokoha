#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	RandomLight�N���X
	�����_���ɓ�����
	*/
	class RandomLight : public GameLight
	{
	private:

		// �҂�����
		double mWaitTime;

	public:

		/// <summary>
		/// �����_���ɓ�����
		/// </summary>
		/// <param name="radius"> ���a </param>
		RandomLight(double radius);

	private:

		void update() override;

	};
}