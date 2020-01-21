#pragma once


#include "../GameObject.h"
#include "../../../Slice/SliceTexture.h"


namespace Kokoha
{
	/*
	GameGoal�N���X
	�S�[���̊��ƂȂ�N���X
	*/
	class GameGoal : public GameObject
	{
	protected:

		// �ړI�n
		Vec2 mGoal;

		// ����
		const double mSpeed;

		// �摜�ƃA�j���[�V����
		SliceTexture mSlide;

	public:

		GameGoal(const Vec2& pos, double speed = 0.0);

	protected:

		virtual void update()override;

		void draw()const override;

		void checkAnother(const GameObject& another)override;

	};
}