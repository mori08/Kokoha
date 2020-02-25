#include "VirusBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// 敵の生成間隔
	constexpr double GENERATE_SPAN = 0.5;

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

	// 評価値の初期値の乱数範囲
	constexpr int32 INIT_COUNT_RANDOM_RANGE = 1;

	// 評価値の増加量
	constexpr int32 COUNT_INCREASE = 2;

	// 前にいたマスの補正
	constexpr int32 PRE_VALUE = 10 * COUNT_INCREASE;
}


Array<int32> Kokoha::VirusBeetleHole::mVisitedCount;


Kokoha::VirusBeetleHole::VirusBeetleHole(const Vec2& pos)
	: GameHole(pos, GENERATE_SPAN)
	, mNowSquare(-1, -1)
	, mPreSquare(-1, -1)
{
	mVisitedCount = Array<int32>(StageData::N, 0);

	for (int32 i = 0; i < StageData::N; ++i)
	{
		mVisitedCount[i] = Random(INIT_COUNT_RANDOM_RANGE);
	}
}


void Kokoha::VirusBeetleHole::update()
{
	GameHole::update();

	// 白い敵の生成
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
		mGenerateSpan.restart();
	}

	// 評価値の更新
	if (mNowSquare != StageData::pixelToSquare(mBody.center)) 
	{
		mPreSquare = mNowSquare;
		mNowSquare = StageData::pixelToSquare(mBody.center);
		mVisitedCount[StageData::squareToInteger(mNowSquare)] += COUNT_INCREASE;
	}
	
	// 移動先の選択
	Point toSquare        = mNowSquare; // 目的マス
	int32 minVisitedCount = (int32)1e9; // 最小評価値
	for (const auto& d : DIRECTION)
	{
		Point square = mNowSquare + d;

		if (!GameManager::instance().getStageData().isWalkAble(square)) { continue; }
		
		int32 visitCount = mVisitedCount[StageData::squareToInteger(square)];
		if (square == mPreSquare)
		{
			visitCount += PRE_VALUE;
		}

		if (visitCount < minVisitedCount)
		{
			minVisitedCount = visitCount;
			toSquare        = square;
		}
	}
	
	walkToGoal(SPEED, StageData::squareToPixel(toSquare));
}
