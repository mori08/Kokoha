#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	RandomEnemy�N���X
	�����_���ȍ��W��ݒ肵�Ĉړ�����
	*/
	class RandomEnemy : public BlackEnemy
	{
	private:

		// �ړI�n
		Vec2 mGoal;

	public:

		RandomEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}