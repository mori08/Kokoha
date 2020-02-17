#include "VirusBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// �G�̐����Ԋu
	constexpr double GENERATE_SPAN = 1.0;

	// ����
	constexpr double SPEED = 1.5;

	// ����
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

	// �����G�̐���
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
	}

	// �]���l�̍X�V
	if (mNowSquare != StageData::pixelToSquare(mBody.center)) 
	{
		mNowSquare = StageData::pixelToSquare(mBody.center);
		++mVisitedCount[StageData::squareToInteger(mNowSquare)];
	}

	// �ړ���̑I��
	Point toSquare        = Point::Zero(); // �ړI�}�X
	int32 minVisitedCount = Inf<int32>;    // �ŏ��]���l
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
