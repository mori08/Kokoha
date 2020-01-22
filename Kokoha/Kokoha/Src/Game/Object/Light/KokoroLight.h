#pragma once


#include "GameLight.h"


namespace Kokoha
{
	class KokoroLight : public GameLight
	{
	public:

		KokoroLight();

	private:

		void update()override;

	};
}