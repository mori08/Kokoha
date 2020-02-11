#include "LeaderGoal.h"
#include "../../GameManager.h"


namespace
{
	// éËâ∫ÇÃêî
	constexpr int32 MINION_NUM = 3;

	// ë¨Ç≥
	constexpr double SPEED = 0.1;
}


Kokoha::LeaderGoal::LeaderGoal(const Vec2& pos)
	: GameGoal(pos)
{
	for (int32 i = 0; i < MINION_NUM; ++i)
	{
		mMinionList.emplace_back(pos, Math::TwoPi * i / MINION_NUM);
	}
}


void Kokoha::LeaderGoal::update()
{
	for (auto& minion : mMinionList)
	{
		minion.update();
	}

	walkToGoal(SPEED, GameManager::instance().getPlayerPos());

	GameGoal::update();
}


void Kokoha::LeaderGoal::checkAnother(const GameObject& another)
{
	GameGoal::checkAnother(another);

	for (auto& minion : mMinionList)
	{
		minion.setGoalPos(mBody.center);
		minion.checkAnother(another);
	}
}


void Kokoha::LeaderGoal::draw() const
{
	GameGoal::draw();

	for (const auto& minion : mMinionList)
	{
		minion.draw();
	}
}


void Kokoha::LeaderGoal::drawLight() const
{
	GameGoal::drawLight();
	
	for (const auto& minion : mMinionList)
	{
		minion.drawLight();
	}

}
