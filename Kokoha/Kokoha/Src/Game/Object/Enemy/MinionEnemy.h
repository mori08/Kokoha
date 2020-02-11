#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	MinionEnemy�N���X
	Leader�N���X�̎�����܂��
	�v���C���[���߂��ƒǂ�������
	*/
	class MinionEnemy : public BlackEnemy
	{
	private:

		// �S�[���̍��W
		Vec2 mGoal;

		// �S�[���ƂȂ��p�x
		double mAngle;

	public:

		MinionEnemy(const Vec2& pos, double angle);

		void update() override;

		void checkAnother(const GameObject& another) override
		{
			BlackEnemy::checkAnother(another);
		}

		void draw() const override
		{
			BlackEnemy::draw();
		}

		void drawLight() const override
		{
			BlackEnemy::drawLight();
		}

		/// <summary>
		/// �S�[���̍��W�̎擾
		/// </summary>
		/// <param name="pos"> �S�[���̍��W </param>
		void setGoalPos(const Vec2& pos)
		{
			mGoal = pos;
		}

	};
}