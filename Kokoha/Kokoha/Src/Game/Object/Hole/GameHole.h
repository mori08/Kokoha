#pragma once


#include "../GameObject.h"


namespace Kokoha
{
	/*
	GameHole�N���X
	WhiteEnemy�𐶐�����I�u�W�F�N�g
	*/
	class GameHole : public GameObject
	{
	public:

		// �ւ̐�
		static const int32 RING_NUM = 2;

	protected:

		// �ړI���W
		Vec2 mGoal;

	private:

		// �ւ��Ȃ��p�x
		std::array<double, RING_NUM> mRingAngleList;

	public:

		GameHole(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void checkAnother(const GameObject&) override
		{
		}

	};
}