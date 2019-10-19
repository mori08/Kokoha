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

	public:

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="objectList"> オブジェクトのリスト </param>
		void update(const Array<AdventureObject>& objectList);

		/// <summary>
		/// 描画
		/// </summary>
		void draw(const Point& cameraPos);

		/// <summary>
		/// プレイヤーの範囲の取得
		/// </summary>
		/// <returns>
		/// 範囲
		/// </returns>
		Rect getRegion()const;

	};
}