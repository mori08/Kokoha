#pragma once

#include "GameGoal.h"
#include "../Enemy/MinionEnemy.h"


namespace Kokoha
{
	/*
	LeaderGoal�N���X
	�v���C���[�ɏ������߂Â�
	MinionEnemy���܂��Ɏ���
	*/
	class LeaderGoal : public GameGoal
	{
	private:

		// �艺���X�g
		Array<MinionEnemy> mMinionList;

	public:

		LeaderGoal(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

		void draw() const override;

		void drawLight() const override;

	};
}