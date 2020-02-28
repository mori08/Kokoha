#include "StraightHole.h"
#include "../Enemy/StraightWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ë¨Ç≥
	constexpr double SPEED = 0.5;

	// ìGÇÃê∂ê¨ä‘äu
	constexpr double GENERATE_SPAN = 5.0;
}


Kokoha::StraightHole::StraightHole(const Vec2& pos, const Vec2& direction)
	: GameHole(pos, GENERATE_SPAN)
	, mEnemyMovement(SPEED*direction)
{
}


void Kokoha::StraightHole::update()
{
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<StraightWhiteEnemy>(mBody.center, mEnemyMovement));
		
		mGenerateSpan.restart();
	}

	GameHole::update();
}
