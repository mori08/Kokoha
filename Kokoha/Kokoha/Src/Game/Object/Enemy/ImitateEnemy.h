#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	ImitateEnemy�N���X
	�v���C���[�̓������܂˂�G
	WASD�L�[�ňړ�
	*/
	class ImitateEnemy : public BlackEnemy
	{
	public:

		ImitateEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}