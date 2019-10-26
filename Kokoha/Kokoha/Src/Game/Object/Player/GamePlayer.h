#pragma once


#include"../GameObject.h"
#include"../../../Slice/Linearly.h"


namespace Kokoha
{
	/*
	GamePlayer�N���X
	GameManager�ň����v���C���[
	*/
	class GamePlayer : public GameObject
	{
	private:

		Linearly<double> mLightRate;

	public:

		GamePlayer(const Vec2& pos);

	private:

		void update()override;

		void draw()const override;

		void drawLight()const override;

	};
}