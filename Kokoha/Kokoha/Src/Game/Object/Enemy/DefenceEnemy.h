#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	DefenceEnemy�N���X
	LastGoal�����G
	*/
	class DefenceEnemy : public BlackEnemy
	{
	private:

		// �S�[���̎�����܂���Ă���Ƃ� true
		bool mDefenceMode;

	protected:

		// �S�[���̍��W
		Vec2 mGoalPos;

		// �ړI�n
		Vec2 mToPos;

	public:

		DefenceEnemy(const Vec2& pos);

	public:

		void update() override;

		void draw() const override { BlackEnemy::draw(); }

		void drawLight() const override { BlackEnemy::drawLight(); }

		void checkAnother(const GameObject& another) override;

	public:

		/// <summary>
		/// �ړI�n�̐ݒ�
		/// </summary>
		/// <param name="pos"> ���W </param>
		void setToPos(const Vec2& pos)
		{
			mToPos = pos;
		}

		/// <summary>
		/// �S�[���̎�����܂��̂𒆎~
		/// </summary>
		void offDefenceMode()
		{
			mDefenceMode = false;
		}

		/// <summary>
		/// �U���p�̖ړI�n�̐ݒ�
		/// </summary>
		virtual void attack() = 0;

	};
}