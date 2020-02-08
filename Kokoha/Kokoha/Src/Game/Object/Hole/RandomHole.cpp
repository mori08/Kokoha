#include "RandomHole.h"
#include "../Enemy/StraightWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// ìGÇê∂ê¨Ç∑ÇÈä‘äu
	constexpr double GENERATE_SPAN = 2.0;

	// ë¨Ç≥
	constexpr double SPEED = 0.9;
}


Kokoha::RandomHole::RandomHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
	, mAngle(Random(0.0, Math::TwoPi))
{
}


void Kokoha::RandomHole::update()
{
	if (mGenerateSpan.update())
	{
		mAngle = mAngle + Math::Pi + Random(-Math::HalfPi, Math::HalfPi);

		const Vec2   movement = SPEED*Vec2(Sin(mAngle), Cos(mAngle));

		GameManager::instance().addObject(std::make_unique<StraightWhiteEnemy>(mBody.center, movement));

		mGenerateSpan.restart();
	}

	GameHole::update();
}
