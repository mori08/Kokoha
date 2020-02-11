#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	SatelliteHole�N���X
	�S�[���̎���Ŕ����G���S�[���Ɍ������Đ�������
	*/
	class SatelliteHole : public GameHole
	{
	private:

		// �S�[���̍��W
		Vec2 mGoalPos;

		// �ړI�n
		Vec2 mToPos;

	public:

		SatelliteHole(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

		void changeGoal();

	};
}