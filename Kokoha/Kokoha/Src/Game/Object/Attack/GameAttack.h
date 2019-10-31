#pragma once


#include "../GameObject.h"

namespace Kokoha
{
	/*
	GameAttack�N���X
	GameManager�ň����U���I�u�W�F�N�g
	�G�I�u�W�F�N�g�ɓ�����Ə����܂�
	*/
	class GameAttack : public GameObject
	{
	private:
	
		// �ړ��̑���
		const double mSpeed;

		// �ړI�l
		Vec2 mGoal;

		// �폜�ł��邩
		bool mIsEraseAble;

	public:

		/// <summary>
		/// �U���I�u�W�F�N�g
		/// </summary>
		/// <param name"pos">    �������W </param>
		/// <param name="speed"> ����     </param>
		GameAttack(const Vec2& pos, double speed);

	protected:

		virtual void update() override;

		virtual void draw() const override;

		bool isEraseAble() const override;

		virtual void checkAnother(const GameObject& another) override;

	};
}