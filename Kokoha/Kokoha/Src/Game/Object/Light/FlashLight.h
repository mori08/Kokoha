#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	FlashLight�N���X
	��ʑS�̂��Ƃ炷
	*/
	class FlashLight : public GameLight
	{
	public:

		FlashLight();

	private:

		void update() override;

	};
}