#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	FlashLightƒNƒ‰ƒX
	‰æ–Ê‘S‘Ì‚ğÆ‚ç‚·
	*/
	class FlashLight : public GameLight
	{
	public:

		FlashLight();

	private:

		void update() override;

	};
}