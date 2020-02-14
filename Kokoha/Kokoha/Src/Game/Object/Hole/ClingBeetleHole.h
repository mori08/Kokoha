#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ClingBeetleHole�N���X
	�v���C���[�ɋ߂Â�
	�����G�𐶐�����
	*/
	class ClingBeetleHole : public GameHole
	{
	private:

		// �ړI���W
		Vec2 mGoal;

	public:

		ClingBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}