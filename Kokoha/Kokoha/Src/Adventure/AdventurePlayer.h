#pragma once


#include "../Slice/SliceTexture.h"
#include "AdventureObject.h"


namespace Kokoha
{
	/*
	AdventurePlayerクラス
	AdventureManagerでのプレイヤー
	座標・範囲の管理 と 描画
	*/
	class AdventurePlayer
	{
	private:

		// x座標
		double mPosX;

		// 画像とアニメーション
		SliceTexture mSlide;

		// 向き x軸について 正 -> +1 , 負 -> -1
		int32 mDirection;

		// 確認マークの表示位置
		Optional<Point> mCheckPos;

	public:

		AdventurePlayer();

		/// <summary>
		/// 設定
		/// </summary>
		void set(int32 posX, int32 direction);

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="objectList"> オブジェクトのリスト </param>
		void update(Array<AdventureObject>& objectList);

		/// <summary>
		/// 描画
		/// </summary>
		void draw(const Point& cameraPos)const;

		/// <summary>
		/// プレイヤーの範囲の取得
		/// </summary>
		/// <returns>
		/// 範囲
		/// </returns>
		Rect getRegion()const;

	private:

		/// <summary>
		/// プレイヤーの移動
		/// </summary>
		/// <param name="objectList"> オブジェクトのリスト </param>
		void walk(const Array<AdventureObject>& objectList);

		/// <summary>
		/// 隣接オブジェクトを確認
		/// </summary>
		/// <param name="objectList"> オブジェクトのリスト </param>
		/// <returns>
		/// 隣接オブジェクトの座標
		/// </returns>
		Optional<Point> check(Array<AdventureObject>& objectList);

	};
}