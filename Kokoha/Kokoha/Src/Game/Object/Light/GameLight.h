#pragma once


#include "../GameObject.h"
#include <limits>


namespace Kokoha
{
	/*
	GameLight�N���X
	GameManager�ň�����
	drawLight��#F0F0F0�ŕ`��
	*/
	class GameLight : public GameObject
	{
	protected:

		// ���̖ړI�n
		Vec2 mGoal;

		// �ړ��̑���
		const double mSpeed;

		// �폜����܂ł̎���(�b)
		double mEraseSecond;

	public:

		/// <summary>
		/// ��
		/// </summary>
		/// <param name="body"       > ���͈̔�     </param>
		/// <param name="speed"      > ����         </param>
		/// <param name="eraseSecond"> �폜���鎞�� </param>
		GameLight(const Circle& body, double speed, double eraseSecond = std::numeric_limits<double>::infinity());

	private:

		virtual void update() override;

		virtual void draw() const override
		{
		}

		virtual void drawLight() const override;

		virtual bool isEraseAble() const override;

	};
}
