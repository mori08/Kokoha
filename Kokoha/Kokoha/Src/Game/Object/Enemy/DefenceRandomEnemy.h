#pragma once


#include "DefenceEnemy.h"


namespace Kokoha
{
	/*
	DefenceRandomEnemyƒNƒ‰ƒX
	DefenceEnemy‚Ì”h¶
	UŒ‚‚Íƒ‰ƒ“ƒ_ƒ€‚É“®‚­
	*/
	class DefenceRandomEnemy : public DefenceEnemy
	{
	public:

		DefenceRandomEnemy(const Vec2& pos);

	private:

		void attack() override;

	};
}