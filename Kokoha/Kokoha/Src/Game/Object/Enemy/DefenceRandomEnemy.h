#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceRandomEnemy�N���X
	DefenceEnemy�̔h��
	�U�����̓����_���ɓ���
	*/
	class DefenceRandomEnemy : public DefenceEnemy
	{
	public:

		DefenceRandomEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}