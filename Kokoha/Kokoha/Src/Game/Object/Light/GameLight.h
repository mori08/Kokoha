#pragma once


#include "../GameObject.h"


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

		// true �̂Ƃ��Â�����
		bool mEraseAble;

		// ���邳(���̕s�����x)
		double mAlpha;

		// �����h�c
		int32 mEquipmentId;

	public:

		/// <summary>
		/// ��
		/// </summary>
		/// <param name="body"       > ���͈̔�     </param>
		/// <param name="speed"      > ����         </param>
		/// <param name="eraseSecond"> �폜���鎞�� </param>
		GameLight(const Circle& body, double speed, double eraseSecond = Inf<double>);

	protected:

		virtual void update() override;

		virtual void draw() const override
		{
		}

		virtual void drawLight() const override;

		virtual bool isEraseAble() const override;

		virtual void checkAnother(const GameObject& another) override {};

	};
}
