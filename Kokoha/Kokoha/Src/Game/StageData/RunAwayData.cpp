#include "RunAwayData.h"
#include "../GameManager.h"


namespace
{
	// 角の方向
	constexpr std::array<Point, 4> CORNER_DIRECTIN
	{
		Point(+1,+1),
		Point(+1,-1),
		Point(-1,-1),
		Point(-1,+1)
	};
}


void Kokoha::RunAwayData::makeCornerGraph()
{
	// 角の検出・頂点の作成
	for (int32 i = 0; i < StageData::N; ++i)
	{
		Point square = StageData::integerToSquare(i);

		// 障害物のあるマスはスキップ
		if (!GameManager::instance().getStageData().isWalkAble(square))
		{
			continue;
		}

		for (const auto& d : CORNER_DIRECTIN)
		{
			// 角になっているか確認
			if (
				!GameManager::instance().getStageData().isWalkAble(square + d)
				&& GameManager::instance().getStageData().isWalkAble(square + Point(d.x, 0))
				&& GameManager::instance().getStageData().isWalkAble(square + Point(0, d.y))
				)
			{
				mCornerVertexList.try_emplace((int32)mCornerVertexList.size(), std::move(CornerGraph::Vertex(square, d)));
			}
		}
	}


}


void Kokoha::RunAwayData::drawDebug()const
{
#ifdef _DEBUG

	for (const auto& vertex : mCornerVertexList)
	{
		Vec2 center
			= StageData::squareToPixel(vertex.second.square)
			+ 0.5 * StageData::SQUARE_SIZE * vertex.second.corner;

		Circle(center, 2).draw(Palette::Red);
	}

#endif // _DEBUG
}
