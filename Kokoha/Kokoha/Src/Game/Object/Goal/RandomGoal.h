#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	RandomGoal�N���X
	�����_���ɓ����S�[��
	*/
	class RandomGoal : public GameGoal
	{
	public:

		RandomGoal(const Vec2& pos);

	private:

		virtual void update()override;

	};
}