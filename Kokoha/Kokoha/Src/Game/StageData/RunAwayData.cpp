#include "RunAwayData.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"


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


bool Kokoha::CornerGraph::Vertex::isConnectAbleEdge(const Vertex& another) const
{
	Vec2 v = another.square - square - 0.5 * corner;
	return (corner.x * corner.y * v.x * v.y) < 0;
}


int32 Kokoha::CornerGraph::Vertex::getCornerDirection(const Vertex& another) const
{
	Vec2 v = another.square - square - 0.5 * corner;
	return (corner.x * v.x > 0) ? 1 : 0;
}


void Kokoha::RunAwayData::makeCornerGraph()
{
	// 角グラフの初期化
	mVertexList.clear();
	mEdgeList.clear();

	// 角の検出・頂点の作成
	for (int32 i = 0; i < StageData::N; ++i)
	{
		Point square = StageData::integerToSquare(i);

		// 障害物のあるマスか
		if (!GameManager::instance().getStageData().isWalkAble(square))
		{
			continue;
		}

		for (const auto& d : CORNER_DIRECTIN)
		{
			// 角になっているか
			if (
				!GameManager::instance().getStageData().isWalkAble(square + d)
				&& GameManager::instance().getStageData().isWalkAble(square + Point(d.x, 0))
				&& GameManager::instance().getStageData().isWalkAble(square + Point(0, d.y))
				)
			{
				mVertexList.try_emplace((int32)mVertexList.size(), std::move(CornerGraph::Vertex(square, d)));
			}
		}
	}

	// 辺の作成
	for (auto itrA = mVertexList.begin(); itrA != mVertexList.end(); ++itrA)
	{
		for (auto itrB = itrA; itrB != mVertexList.end(); ++itrB)
		{
			// 同じマスならスキップ
			if (itrA->second.square == itrB->second.square) { continue; }

			// それぞれの頂点がそれぞれの角方向にあるか
			if (!itrA->second.isConnectAbleEdge(itrB->second)) { continue; }
			if (!itrB->second.isConnectAbleEdge(itrA->second)) { continue; }

			// 辺をひけるか
			bool isEdge = true;

			// 2頂点で作られる格子点に障害物があるか
			for (const Point& pos : getGridPoint(getRectFromTwoPoint(itrA->second.square, itrB->second.square)))
			{
				if (GameManager::instance().getStageData().isWalkAble(pos)) { continue; }

				isEdge = false;
				break;
			}

			if (isEdge)
			{
				mEdgeList[itrA->first][itrB->first] = itrA->second.getCornerDirection(itrB->second);
				mEdgeList[itrB->first][itrA->first] = itrB->second.getCornerDirection(itrA->second);
			}
		}
	}
}


void Kokoha::RunAwayData::drawDebug()const
{
#ifdef _DEBUG

	ClearPrint();

	for (const auto& vertex : mVertexList)
	{
		Vec2 center
			= StageData::squareToPixel(vertex.second.square)
			+ 0.5 * StageData::SQUARE_SIZE * vertex.second.corner;

		Circle(center, 2).draw(Palette::Red);

		if (Circle(center, 4).mouseOver())
		{
			Print << vertex.second.square;

			for (const auto& to : mEdgeList.find(vertex.first)->second)
			{
				const auto& toVertex = mVertexList.find(to.first)->second;
				center
					= StageData::squareToPixel(toVertex.square)
					+ 0.5 * StageData::SQUARE_SIZE * toVertex.corner;

				Circle(center, 5).drawFrame(2, Palette::Blue);
			}
		}
	}

#endif // _DEBUG
}
