#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	ImitateGoal�N���X
	�v���C���[�̓������܂˂�S�[��
	WASD�L�[�ňڑ�
	*/
	class ImitateGoal : public GameGoal
	{
	public:

		ImitateGoal(const Vec2& pos);

	private:

		void update() override;

	};
}