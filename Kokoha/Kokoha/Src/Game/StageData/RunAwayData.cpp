#include "RunAwayData.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"


namespace
{
	// �p�̕���
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
	// �p�O���t�̏�����
	mVertexList.clear();
	mEdgeList.clear();

	// �p�̌��o�E���_�̍쐬
	for (int32 i = 0; i < StageData::N; ++i)
	{
		Point square = StageData::integerToSquare(i);

		// ��Q���̂���}�X��
		if (!GameManager::instance().getStageData().isWalkAble(square))
		{
			continue;
		}

		for (const auto& d : CORNER_DIRECTIN)
		{
			// �p�ɂȂ��Ă��邩
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

	// �ӂ̍쐬
	for (auto itrA = mVertexList.begin(); itrA != mVertexList.end(); ++itrA)
	{
		for (auto itrB = itrA; itrB != mVertexList.end(); ++itrB)
		{
			// �����}�X�Ȃ�X�L�b�v
			if (itrA->second.square == itrB->second.square) { continue; }

			// ���ꂼ��̒��_�����ꂼ��̊p�����ɂ��邩
			if (!itrA->second.isConnectAbleEdge(itrB->second)) { continue; }
			if (!itrB->second.isConnectAbleEdge(itrA->second)) { continue; }

			// �ӂ��Ђ��邩
			bool isEdge = true;

			// 2���_�ō����i�q�_�ɏ�Q�������邩
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
