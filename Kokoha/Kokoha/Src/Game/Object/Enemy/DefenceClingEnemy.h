#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceClingEnemy�N���X
	DefenceEnemy�̔h��
	�U�����̓v���C���[�ɋ߂Â�
	*/
	class DefenceClingEnemy : public DefenceEnemy
	{
	public:

		DefenceClingEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}