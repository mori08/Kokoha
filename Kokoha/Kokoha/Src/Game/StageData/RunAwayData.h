#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	角グラフ
	角を頂点としたグラフでマスの評価などに役立たせる
	*/
	namespace CornerGraph
	{
		// 頂点
		class Vertex
		{
		public:

			// マス座標
			const Point square;

			// 角の方向
			const Point corner;

		public:

			/// <summary>
			/// 角グラフの頂点
			/// </summary>
			/// <param name="s"> マス座標 </param>
			/// <param name="c"> 角の方向 </param>
			Vertex(const Point& s, const Point& c)
				: square(s)
				, corner(c)
			{
			}

		public:

			/// <summary>
			/// 角から見た方向が有効なものか
			/// </summary>
			/// <param name="another"> 辺を引きたい頂点 </param>
			bool isConnectAbleEdge(const Vertex& another)const;

			/// <summary>
			/// 角から見た方向
			/// </summary>
			/// <param name="another"> 辺を引きたい頂点 </param>
			int32 getCornerDirection(const Vertex& another)const;

		};
	}


	/*
	RunAwayDataクラス
	プレイヤーから逃げるオブジェクトが必要とする情報の計算・管理
	*/
	class RunAwayData
	{
	private:

		// 角グラフの頂点のリスト
		std::unordered_map<int32, CornerGraph::Vertex> mVertexList;

		// 角グラフの辺のリスト [端点i][端点j] = 方向
		std::unordered_map<int32, std::unordered_map<int32, int32>> mEdgeList;

	public:

		/// <summary>
		/// 角グラフの作成
		/// </summary>
		/// <remarks>
		/// O(N^3)かかる処理
		/// LoadSceneの派生クラスを使って処理する
		/// </remarks>
		void makeCornerGraph();

		/// <summary>
		/// デバッグ用の描画
		/// </summary>
		/// <remarks>
		/// クラス完成後に削除
		/// </remarks>
		void drawDebug()const;

	};
}