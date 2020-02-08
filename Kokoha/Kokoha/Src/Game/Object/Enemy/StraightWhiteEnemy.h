#pragma once


#include "WhiteEnemy.h"


namespace Kokoha
{
	/*
	StraightWhiteEnemy�N���X
	���i���锒���G
	�R���X�g���N�^�ŕ������w��
	*/
	class StraightWhiteEnemy : public WhiteEnemy
	{
	private:

		// �ړ��x�N�g��
		Vec2 mMovement;

	public:

		/// <summary>
		/// ���i���锒���G
		/// </summary>
		/// <param name="pos"> �������W </param>
		/// <param name="movement"> �ړ��� </param>
		StraightWhiteEnemy(const Vec2& pos, const Vec2& movement);

	private:

		void update() override;

	};
}