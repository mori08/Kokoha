#pragma once


#include "GameGoal.h"


namespace Kokoha
{
	/*
	RunAwayGoal�N���X
	�v���C���[���瓦����S�[��
	*/
	class RunAwayGoal : public GameGoal
	{
	private:

		// �ړI�n��ύX���鎞��
		double mChangeGoalSecond;

	public:

		/// <summary>
		/// �v���C���[���瓦����S�[��
		/// </summary>
		/// <param name="pos"> �������W </param>
		RunAwayGoal(const Vec2& pos);

	private:

		void update()override;

	};
}