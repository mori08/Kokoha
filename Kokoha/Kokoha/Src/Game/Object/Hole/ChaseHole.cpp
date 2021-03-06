#include "ChaseHole.h"
#include "../Enemy/ChaseEnemy.h"
#include "../../GameManager.h"


namespace
{
	// 生成する間隔
	constexpr double GENERATE_SPAN = 4.0;
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
