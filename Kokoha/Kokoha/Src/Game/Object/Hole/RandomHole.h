#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	RandomHole�N���X
	�����_���ȕ����ɓG�𐶐�����
	*/
	class RandomHole : public GameHole
	{
	private:

		// �G�𐶐�����p�x
		double mAngle;

	public:

		RandomHole(const Vec2& pos);

	private:

		void update() override;

	};
}