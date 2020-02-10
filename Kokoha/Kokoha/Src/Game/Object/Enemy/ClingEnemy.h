#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	ClingEnemy�N���X
	�v���C���[�̋߂��Ɉړ�����G
	*/
	class ClingEnemy : public BlackEnemy
	{
	private:

		// �S�[��
		Vec2 mGoal;

	public:

		ClingEnemy(const Vec2& pos);

	private:

		void update();

	};
}