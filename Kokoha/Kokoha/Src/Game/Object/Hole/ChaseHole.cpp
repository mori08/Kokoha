#include "ChaseHole.h"
#include "../Enemy/ChaseEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ê∂ê¨Ç∑ÇÈä‘äu
	constexpr double GENERATE_SPAN = 6.0;
}


Kokoha::ChaseHole::ChaseHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
{
}


void Kokoha::ChaseHole::update()
{
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject
		(
			std::make_unique<ChaseEnemy<WhiteEnemy>>(mBody.center)
		);

		mGenerateSpan.restart();
	}

	GameHole::update();
}
