#include "TutorialGoalState.h"
#include "../../GameManager.h"
#include "../../Object/Goal/TutorialGoal.h"


namespace
{
	// ƒS[ƒ‹‚ÌŒó•â“_
	const Array<Vec2> GOAL_POS
	{
		Kokoha::StageData::squareToPixel(Point(6,1)),
		Kokoha::StageData::squareToPixel(Point(6,13)),
		Kokoha::StageData::squareToPixel(Point(18,1)),
		Kokoha::StageData::squareToPixel(Point(18,13))
	};

	// ƒS[ƒ‹‚Æ‚Ì‹——£‚Ì•]‰¿
	constexpr double MAX_DISTANCE = 300.0;
}


Kokoha::TutorialGoalState::TutorialGoalState()
	: TutorialState(U"‹N“®€”õ’†...", U"ƒS[ƒ‹‚ğ’T‚·")
{
	const Vec2 playerPos = GameManager::instance().getPlayerPos();

	       goalPos     = GOAL_POS[0];
	double maxDistance = 0;
	for (const auto& pos : GOAL_POS)
	{
		if (maxDistance < pos.distanceFrom(playerPos))
		{
			goalPos     = pos;
			maxDistance = pos.distanceFrom(playerPos);
		}
	}

	GameManager::instance().addObject(std::make_unique<TutorialGoal>(goalPos));
}


void Kokoha::TutorialGoalState::update()
{
	TutorialState::update();

	GameManager::instance().update();

	const Vec2 playerPos = GameManager::instance().getPlayerPos();
	const double rate = (MAX_DISTANCE - goalPos.distanceFrom(playerPos)) / MAX_DISTANCE;
	updateAchieveRate(rate);
}
