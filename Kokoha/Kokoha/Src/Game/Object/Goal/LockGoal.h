#pragma once


#include "GameGoal.h"
#include "Key/GameGoalKey.h"


namespace Kokoha
{
	/*
	LockGoal�N���X
	���̂��������S�[��
	GameGoalKey����������
	*/
	class LockGoal : public GameGoal
	{
	private:

		// ���I�u�W�F�N�g�̃��X�g
		Array<GameGoalKey> mKeyList;

		// �����������Ă��邩
		bool mIsOpened;

	public:

		LockGoal(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void checkAnother(const GameObject& another) override;

	};
}