#include "SatelliteHole.h"
#include "../Enemy/StraightWhiteEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace
{
	// ë¨Ç≥
	constexpr double SPEED = 0.6;

	// ÉSÅ[ÉãÇ∆ÇÃãóó£
	constexpr double DISTANCE = 128.0;

	// îíÇ¢ìGÇë≈ÇøèoÇ∑ë¨Ç≥
	constexpr double SHOT_SPEED = 1.2;
}


Kokoha::SatelliteHole::SatelliteHole(const Vec2& pos)
	: GameHole(pos, 0)
	, mGoalPos(pos)
	, mToPos(pos)
{
}


void Kokoha::SatelliteHole::update()
{
	if (!GameManager::instance().getStageData().isWalkAble(mToPos))
	{
		changeGoal();
	}

	if (StageData::pixelToInteger(mToPos) == StageData::pixelToInteger(mBody.center))
	{
		changeGoal();

		// îíÇ¢ìGÇê∂ê¨
		const Vec2 movement = SHOT_SPEED * (mGoalPos - mBody.center).normalized();
		GameManager::instance().addObject
		(
			std::make_unique<StraightWhiteEnemy>(mBody.center, movement)
		);
	}

	walkToGoal(SPEED, mToPos);

	GameHole::update();
}


void Kokoha::SatelliteHole::checkAnother(const GameObject& another)
{
	if (auto pos = another.checkTypeAndGetPos(ObjectType::GOAL))
	{
		mGoalPos = pos.value();
	}

	GameHole::checkAnother(another);
}


void Kokoha::SatelliteHole::changeGoal()
{
	mToPos = mGoalPos + DISTANCE * angleToVec(Random(0.0, Math::TwoPi));
}
