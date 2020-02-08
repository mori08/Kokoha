#pragma once


#include "GameEnemy.h"
#include "../../../Slice/Linearly.h"


namespace Kokoha
{
	/*
	WhiteEnemy�N���X
	�����G�I�u�W�F�N�g�̊��N���X
	�U���ɓ�����Ə�����
	*/
	class WhiteEnemy : public GameEnemy
	{
	private:

		// �폜����
		double mEraseSecond;

		// �A���t�@�l
		Linearly<double> mAlpha;

		// �폜����
		bool mEraseAble;

	public:

		WhiteEnemy(const Vec2& pos);

	private:

		virtual void update() override;

		bool isEraseAble()const override;

		virtual void checkAnother(const GameObject& another) override;

		void draw() const override;

	};
}