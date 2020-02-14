#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	PatrolTeamEnemy�N���X
	�߂Â��ƃ`�[���Œǂ�������
	*/
	class PatrolTeamEnemy : public BlackEnemy
	{
	private:

		// �v���C���[��ǂ�������Ƃ� true
		static bool sIsChasing;

		// �ړI�n
		Vec2 mGoal;

		// �ړI�n�ύX�̎���
		double mChangeGoalSecond;

	public:

		PatrolTeamEnemy(const Vec2& pos);

	private:

		void update() override;

		void draw()const override;

		void checkAnother(const GameObject& another) override;

	};
}