#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	EnemyLight�N���X
	�v���C���[�Ɉ�ԋ߂��G��ǐ�
	*/
	class EnemyLight : public GameLight
	{
	private:

		// �v���C���[�̍��W
		Vec2 mPlayerPos;

		// ��ԋ߂��G�Ƃ̍ŒZ����
		double mMinDistance;

	public:

		EnemyLight(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

	};
}