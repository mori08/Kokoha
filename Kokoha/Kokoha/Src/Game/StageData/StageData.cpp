#include <limits>
#include "StageData.h"
#include "../../MyColor.h"


namespace 
{
	// 経路探索を行う最短距離
	constexpr double MIN_LENGTH = 2.0;

	// 無限大
	constexpr double INF = std::numeric_limits<double>::infinity();
}


bool Kokoha::StageData::isWalkAble(const Point& square) const
{
	if (square.x < 0 || square.x >= WIDTH)  { return false; }
	if (square.y < 0 || square.y >= HEIGHT) { return false; }
	return !mTerrain[squareToInteger(square)];
}


Vec2 Kokoha::StageData::getPath(const Vec2& pixelS, const Vec2& pixelT) const
{
	if (!isWalkAble(pixelS) || !isWalkAble(pixelT) || (pixelS - pixelT).length() < MIN_LENGTH) 
	{ 
		return Vec2::Zero(); 
	}

	const int32 s = squareToInteger(pixelToSquare(pixelS));
	const int32 t = squareToInteger(pixelToSquare(pixelT));

	if (s == t) 
	{
		return (pixelT - pixelS).normalize();
	}

	return mPath[s][t];
}


double Kokoha::StageData::getDistance(const Vec2& pixelS, const Vec2& pixelT) const
{
	if (!isWalkAble(pixelS) || !isWalkAble(pixelT))
	{
		return INF;
	}

	return mDistance[squareToInteger(pixelToSquare(pixelS))][squareToInteger(pixelToSquare(pixelT))];
}


void Kokoha::StageData::init()
{
	// 地形のリセット
	for (int32 i = 0; i < N; ++i)
	{
		mTerrain[i] = false;

		// 経路距離のリセット
		for (int32 j = 0; j < N; ++j)
		{
			mPath    [i][j] = Vec2::Zero();
			mDistance[i][j] = INF;
		}
	}
}


void Kokoha::StageData::searchPath()
{
	// 隣接するマスに辺をつける
	for (int32 i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			auto edge = getEdge(i, j);
			mPath    [i][j] = edge.first;
			mDistance[i][j] = edge.second;
		}
	}

	// ワーシャルフロイド法を用いた経路探索
	for (int32 k = 0; k < N; ++k)
	{
		for (int32 i = 0; i < N; ++i)
		{
			for (int32 j = 0; j < N; ++j)
			{
				if (mDistance[i][j] > mDistance[i][k] + mDistance[k][j])
				{
					mDistance[i][j] = mDistance[i][k] + mDistance[k][j];
					mPath    [i][j] = mPath    [i][k];
				}
			}
		}
	}
}


void Kokoha::StageData::draw() const
{
	for (int32 i = 0; i < N; ++i)
	{
		const Point square = integerToSquare(i);
		if (isWalkAble(square)) { continue; }
		Rect(SQUARE_SIZE * square, SQUARE_SIZE).draw(MyBlack);
	}
}


std::pair<Vec2, double> Kokoha::StageData::getEdge(int s, int t) const
{
	const Point squareS = integerToSquare(s);
	const Point squareT = integerToSquare(t);
	const Point sub = squareT - squareS;

	// 始点か終点が壁になるとき
	if (!isWalkAble(squareS) || !isWalkAble(squareT))
	{
		return { Vec2::Zero(),INF }; // 辺なし
	}

	// 始点と終点が離れているとき
	if (Abs(sub.x) > 1 || Abs(sub.y) > 1)
	{
		return { Vec2::Zero(),INF }; // 辺なし
	}

	// 始点と終点が同じ点であるとき
	if (sub.isZero())
	{
		return { Vec2::Zero(),0 }; // コスト0
	}

	// 始点に対して終点がすぐ隣にあるとき
	if (sub.x == 0 || sub.y == 0)
	{
		return { Vec2(sub),1 };
	}

	// 始点に対して終点がすぐ斜めにあるとき

	// その横に壁があるとき
	if (!isWalkAble(Point(squareS.x, squareT.y)) || !isWalkAble(Point(squareT.x, squareS.y)))
	{
		return { Vec2::Zero(),INF }; // 辺なし
	}

	return { Vec2(sub).normalize(),Sqrt(2) };
}
