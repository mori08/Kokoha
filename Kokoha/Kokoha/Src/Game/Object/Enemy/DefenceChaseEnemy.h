#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceChaseEnemy�N���X
	DefenceEnemy�̔h��
	�U�����̓v���C���[��ǐՂ���
	*/
	class DefenceChaseEnemy : public DefenceEnemy
	{
	public:

		DefenceChaseEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}