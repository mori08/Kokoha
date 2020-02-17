#include "VirusBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// 敵の生成間隔
	constexpr double GENERATE_SPAN = 1.0;

	// 速さ
	constexpr double SPEED = 1.5;

	// 方向
	const Array<Point> DIRECTION
	{
		Point::Right(),
		Point::Left(),
		Point::Up(),
		Point::Down()
	};
}


Kokoha::VirusBeetleHole::VirusBeetleHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
	, mNowSquare(-1, -1)
	, mVisitedCount(StageData::N, 0)
{
	for (int32 i = 0; i < StageData::N; ++i)
	{
		if (GameManager::instance().getStageData().isWalkAble(StageData::integerToSquare(i)))
		{
			continue;
		}

		mVisitedCount[i] = Inf<int32>;
	}
}


void Kokoha::VirusBeetleHole::update()
{
	GameHole::update();

	// 白い敵の生成
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
	}

	// 評価値の更新
	if (mNowSquare != StageData::pixelToSquare(mBody.center)) 
	{
		mNowSquare = StageData::pixelToSquare(mBody.center);
		++mVisitedCount[StageData::squareToInteger(mNowSquare)];
	}

	// 移動先の選択
	Point toSquare        = Point::Zero(); // 目的マス
	int32 minVisitedCount = Inf<int32>;    // 最小評価値
	for (const auto& d : DIRECTION)
	{
		Point square = mNowSquare + d;

		if (!GameManager::instance().getStageData().isWalkAble(square)) { continue; }

		if (mVisitedCount[StageData::squareToInteger(square)] < minVisitedCount)
		{
			minVisitedCount = mVisitedCount[StageData::squareToInteger(square)];
			toSquare        = square;
		}
	}

	walkToGoal(SPEED, StageData::squareToPixel(toSquare));
}
