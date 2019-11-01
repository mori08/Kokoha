#pragma once


#include "GameAttack.h"


namespace Kokoha
{
	/*
	ChaseEnemyAttack�N���X
	�����G�I�u�W�F�N�g��ǂ��U���I�u�W�F�N�g
	*/
	class ChaseEnemyAttack : public GameAttack
	{
	private:

		double mMinDistance;

	public:

		ChaseEnemyAttack(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another);

	};
}