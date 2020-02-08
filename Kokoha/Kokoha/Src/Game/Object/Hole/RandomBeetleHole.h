#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	RandomBeetleHole�N���X
	�ړI�n�Ɉړ��������CEggWhiteEnemey�𐶐�����
	*/
	class RandomBeetleHole : public GameHole
	{
	protected:

		// �ړI���W
		Vec2 mGoal;

	public:

		RandomBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}