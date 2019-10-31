#pragma once


#include "GameEnemy.h"


namespace Kokoha
{
	/*
	WhiteEnemy�N���X
	�����G�I�u�W�F�N�g�̊��N���X
	�U���ɓ�����Ə�����
	*/
	class WhiteEnemy : public GameEnemy
	{
	public:

		WhiteEnemy(const Vec2& pos);

	private:

		bool isEraseAble()const override;

		void checkAnother(const GameObject& another) override;

	};
}