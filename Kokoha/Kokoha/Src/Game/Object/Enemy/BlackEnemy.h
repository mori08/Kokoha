#pragma once


#include "GameEnemy.h"


namespace Kokoha
{
	/*
	BlackEnemy�N���X
	�����G�I�u�W�F�N�g�̊��N���X
	*/
	class BlackEnemy : public GameEnemy
	{
	public:

		BlackEnemy(const Vec2& pos);

	private:

		bool isEraseAble()const override
		{
			return false;
		}

		void checkAnother(const GameObject& another)
		{
			GameEnemy::checkAnother(another);
		}

	};
}