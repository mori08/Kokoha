#pragma once


#include "WhiteEnemy.h"


namespace Kokoha
{
	/*
	EggWhiteEnemy�N���X
	�����_���ȕ����ɏ�����������
	*/
	class EggWhiteEnemy : public WhiteEnemy
	{
	private:

		// �p�x
		const double mAngle;

	public:

		EggWhiteEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}