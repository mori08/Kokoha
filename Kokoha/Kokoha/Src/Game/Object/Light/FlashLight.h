#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	FlashLightクラス
	画面全体を照らす
	*/
	class FlashLight : public GameLight
	{
	public:

		FlashLight();

	private:

		void update() override;

	};
}