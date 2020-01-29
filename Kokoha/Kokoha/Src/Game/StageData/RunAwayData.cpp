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

	// 座標の評価時の距離の比
	constexpr double RATE = 1.5;
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

			// 辺の作成
			if (isEdge)
			{
				mEdgeList[itrA->first][itrB->first] = itrA->second.getCornerDirection(itrB->second);
				itrA->second.mEdgeNum[itrA->second.getCornerDirection(itrB->second)]++;

				mEdgeList[itrB->first][itrA->first] = itrB->second.getCornerDirection(itrA->second);
				itrB->second.mEdgeNum[itrB->second.getCornerDirection(itrA->second)]++;
			}
		}
	}

	// 辺の削除
	int32 vertexNum = (int32)mVertexList.size();
	for (int32 i : Range(0, vertexNum - 1))
	{
		removeNoVertex(i);
	}

	// 逃げる用の候補点
	mRunAwaySuggest = Array<std::set<int32>>(StageData::N);
	for (int32 i : Range(0, StageData::N - 1))
	{
		// 各マスについて
		Point square = StageData::integerToSquare(i);

		// 各頂点
		for (const auto& vertex : mVertexList)
		{
			bool isEdge = true;
			
			for (const Point& pos : getGridPoint(getRectFromTwoPoint(square, vertex.second.square)))
			{
				if (GameManager::instance().getStageData().isWalkAble(pos)) { continue; }

				isEdge = false;
				break;
			}

			if (isEdge)
			{
				mRunAwaySuggest[i].insert(StageData::squareToInteger(vertex.second.square));
			}
		}
	}
}


Vec2 Kokoha::RunAwayData::suggest(const Vec2& pixel) const
{
	double minDistance = Inf<double>;
	Vec2   rtn         = pixel;

	const Vec2& playerPos = GameManager::instance().getPlayerPos();

	for (const auto& i : mRunAwaySuggest[StageData::pixelToInteger(pixel)])
	{
		const Vec2 pos = StageData::integerToPixel(i);

		const double myDistance     = GameManager::instance().getStageData().getDistance(pos, pixel    );
		const double playerDistance = GameManager::instance().getStageData().getDistance(pos, playerPos);

		double distance = myDistance - RATE * playerDistance;

		if (distance > minDistance) { continue; }

		minDistance = distance;
		rtn         = pos;
	}

	return std::move(rtn);
}


void Kokoha::RunAwayData::drawDebug()const
{
#ifdef _DEBUG

	static bool debugMode = false;
	debugMode ^= Key0.up();

	if (!debugMode) { return; }
	
	for (const auto& vertex : mVertexList)
	{
		Vec2 center
			= StageData::squareToPixel(vertex.second.square)
			+ 0.5 * StageData::SQUARE_SIZE * vertex.second.corner;
		
		Circle(center, 2).draw(Palette::Red);

		if (Circle(center, 4).mouseOver())
		{
			for (const auto& to : mEdgeList.find(vertex.first)->second)
			{
				const auto& toVertex = mVertexList.find(to.first)->second;
				center
					= StageData::squareToPixel(toVertex.square)
					+ 0.5 * StageData::SQUARE_SIZE * toVertex.corner;

				Color color = to.second ? Palette::Blue : Palette::Lime;

				Circle(center, 6).drawFrame(3, color);
			}
		}
	}

	if (!GameManager::instance().getStageData().isWalkAble(Cursor::PosF())) { return; }
	
	for (const auto& i : mRunAwaySuggest[StageData::pixelToInteger(Cursor::PosF())])
	{
		Circle(StageData::integerToPixel(i), 5).draw(Palette::Yellow);
	}

#endif // _DEBUG
}


void Kokoha::RunAwayData::removeNoVertex(int32 vertexId)
{
	// 頂点が存在しないとき
	if (!mVertexList.count(vertexId)) { return; }

	// 不要と判断できないとき
	if (mVertexList.find(vertexId)->second.mEdgeNum[0] != 0 && mVertexList.find(vertexId)->second.mEdgeNum[1] != 0)
	{
		return;
	}

	// 頂点の削除
	mVertexList.erase(vertexId);

	// 隣接頂点側からの辺の削除
	for (auto& to : mEdgeList[vertexId])
	{
		mVertexList.find(to.first)->second.mEdgeNum[mEdgeList[to.first][vertexId]]--;
		mEdgeList[to.first].erase(vertexId);
	}

	// 隣接頂点で再帰
	for (auto& to : mEdgeList[vertexId])
	{
		removeNoVertex(to.first);
	}

	// 辺の削除
	mEdgeList.erase(vertexId);
}
