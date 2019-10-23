#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	StageDataクラス
	GameManagerで扱う地形の管理や経路探索を行います.
	
	注) 2種類の座標を以下の表現で使い分ける.
	Vec2  pixel  -> ピクセル座標 : 当たり判定や描画に使用
	Point square -> マス座標     : 障害物の管理や経路探索に使用
	*/
	class StageData
	{
	public:

		static constexpr int32 WIDTH       = 20;           // ステージの幅(マス)
		static constexpr int32 HEIGHT      = 15;           // ステージの高さ(マス)
		static constexpr int32 N           = WIDTH*HEIGHT; // マス目数
		static constexpr int32 SQUARE_SIZE = 32;           // 1マスの一辺の長さ(ピクセル)

	private:

		// 地形 trueのとき障害物あり
		std::array<bool, N> mTerrain;

		// [i][j] : i -> j への最短経路(単位ベクトル)
		std::array<std::array<Vec2, N>, N> mPath;

		// [i][j] : i -> j への最短距離(マス数)
		std::array<std::array<double, N>, N> mDistance;

	public:

		/// <summary>
		/// ピクセル座標からマス座標に変換
		/// </summary>
		/// <param name="pixel"> ピクセル座標 </param>
		/// <returns>
		/// マス座標
		/// </returns>
		static constexpr Point pixelToSquare(const Vec2& pixel)
		{
			return Floor((pixel/SQUARE_SIZE)).asPoint();
		}

		/// <summary>
		/// マス座標からピクセル座標に変換
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns>
		/// マスの中心のピクセル座標
		/// </returns>
		static constexpr Vec2 squareToPixel(const Point& square)
		{
			return SQUARE_SIZE * (Vec2::One() * square + Vec2::One() / 2.0);
		}

		/// <summary>
		/// 整数値をそれに対応するマス座標に変換
		/// </summary>
		/// <param name="integer"> 整数値 </param>
		/// <retruns>
		/// マス座標
		/// </returns>
		static constexpr Point integerToSquare(int32 integer)
		{
			return Point(integer % WIDTH, integer / WIDTH);
		}

		/// <summary>
		/// マス座標をそれに対応する整数値に変換
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns>
		/// マス座標に対応する整数値
		/// </returns>
		static constexpr int32 squareToInteger(const Point& square)
		{
			return square.x + WIDTH * square.y;
		}

	public:

		/// <summary>
		/// 指定されたマス座標が行動可能か
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns>
		/// ステージ外であるときや障害物があるとき false , それ以外のとき true
		/// </returns>
		bool isWalkAble(const Point& square) const;

		/// <summary>
		/// 指定されたピクセル座標が行動可能か
		/// </summary>
		/// <param name="pixel"> ピクセル座標 </param>
		/// <returns>
		/// ステージ外であるときや障害物があるとき false , それ以外のとき true
		/// </returns>
		bool isWalkAble(const Vec2& pixel) const
		{
			return isWalkAble(pixelToSquare(pixel));
		}

		/// <summary>
		/// 最短経路の取得
		/// </summary>
		/// <param name="pixelS"> 始点 (ピクセル座標) </param>
		/// <param name="pixelT"> 終点 (ピクセル座標) </param>
		/// <returns>
		/// 経路上で最初に進む方向の単位ベクトル, 行くことができないとき Vec2::Zero()
		/// </returns>
		Vec2 getPath(const Vec2& pixelS, const Vec2& pixelT)const;

		/// <summary>
		/// 最短距離の取得
		/// </summary>
		/// <param name="pixelS"> 始点 (ピクセル座標) </param>
		/// <param name="pixelT"> 終点 (ピクセル座標) </param>
		/// <returns>
		/// 距離(マス数), 行くことができないとき 無限大 
		/// </returns>
		double getDistance(const Vec2& pixelS, const Vec2& pixelT)const;

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// 障害物の設置
		/// </summary>
		/// <param name="square"> マス座標 </param>
		void setWall(const Point& square)
		{
			mTerrain[squareToInteger(square)] = true;
		}

		/// <summary>
		/// ワーシャル・フロイド法を用いた経路探索
		/// </summary>
		/// <remarks>
		/// O(N^3)かかる処理です.
		/// 必ずLoadSceneの派生クラスを使って別スレッドで処理する.
		/// </remarks>
		void searchPath();

		/// <summary>
		/// 地形の描画
		/// </summary>
		void darw()const;

	private:

		/// <summary>
		/// 2頂点間の辺を取得
		/// </summary>
		/// <param name="s"> 始点を示す整数値 </param>
		/// <param name="t"> 終点を示す整数値 </param>
		/// <returns>
		/// 辺 { 方向,コスト } , 辺が存在しないとき { Vec::Zero(),INF }
		/// </returns>
		std::pair<Vec2, double> getEdge(int s, int t) const;

	};
}