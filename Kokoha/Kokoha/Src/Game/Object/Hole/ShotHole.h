#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ShotHole�N���X
	�v���C���[�Ɍ������Ĕ����G�𐶐�����
	*/
	class ShotHole : public GameHole
	{
	private:

		// �S�[���̍��W
		Vec2 mGoalPos;

		// �v���C���[�̍��W
		Vec2 mPlayerPos;

	public:

		ShotHole(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another);

	};
}