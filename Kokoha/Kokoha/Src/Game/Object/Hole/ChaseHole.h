#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ChaseHole�N���X
	�v���C���[��ǐՂ��锒���G�𐶐�����
	*/
	class ChaseHole : public GameHole
	{
	public:

		ChaseHole(const Vec2& pos);

	private:

		void update() override;

	};
}