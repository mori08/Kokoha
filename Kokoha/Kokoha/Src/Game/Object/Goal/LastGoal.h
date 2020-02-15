#pragma once


#include "GameGoal.h"
#include "Key/GameGoalKey.h"
#include "../Enemy/DefenceEnemy.h"


namespace Kokoha
{
	/*
	LastGoal�N���X
	��������o��
	�����G�����C�����J�����邽�ъJ������
	*/
	class LastGoal : public GameGoal
	{
	private:

		// ���̓G
		Array<std::unique_ptr<DefenceEnemy>> mDefenceEnemyList;

		// ���I�u�W�F�N�g�̃��X�g
		std::list<GameGoalKey> mKeyList;

		// �����������Ă��邩
		bool mIsOpened;

	public:

		LastGoal(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void drawLight() const override;

		void checkAnother(const GameObject& another) override;

	};

}
