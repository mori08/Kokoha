#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceGuardEnemy�N���X
	DefenceEnemy�̔h��
	�U�����̓S�[���ƃv���C���[�̊Ԃɓ���
	*/
	class DefenceGuardEnemy : public DefenceEnemy
	{
	public:

		DefenceGuardEnemy(const Vec2& pos);

	private:

		void attack()override;

	};
}