#include "VirusBeetleHole.h"
#include "../Enemy/EggWhiteEnemy.h"
#include "../../GameManager.h"


namespace
{
	// �G�̐����Ԋu
	constexpr double GENERATE_SPAN = 0.5;

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

	// �]���l�̏����l�̗����͈�
	constexpr int32 INIT_COUNT_RANDOM_RANGE = 1;

	// �]���l�̑�����
	constexpr int32 COUNT_INCREASE = 2;

	// �O�ɂ����}�X�̕␳
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

	// �����G�̐���
	if (mGenerateSpan.update())
	{
		GameManager::instance().addObject(std::make_unique<EggWhiteEnemy>(mBody.center));
		mGenerateSpan.restart();
	}

	// �]���l�̍X�V
	if (mNowSquare != StageData::pixelToSquare(mBody.center)) 
	{
		mPreSquare = mNowSquare;
		mNowSquare = StageData::pixelToSquare(mBody.center);
		mVisitedCount[StageData::squareToInteger(mNowSquare)] += COUNT_INCREASE;
	}
	
	// �ړ���̑I��
	Point toSquare        = mNowSquare; // �ړI�}�X
	int32 minVisitedCount = (int32)1e9; // �ŏ��]���l
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
