#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	AdventureObjectクラス
	AdventureManagerで使用するオブジェクト
	決定キーが押されたとき
	*/
	class AdventureObject
	{
	private:

		// 当たり判定の範囲
		Rect mRegion;

		// 画像名
		String mTextureName;

		// 不透明度
		double mAlpha;

		// 通過可能か
		const bool mIsPassing;

		// 決定を押されたときの処理
		std::function<void()> mOnClick;

	public:

		/// <summary>
		/// Adventureのオブジェクト
		/// </summary>
		/// <param name="pos">         座標       </param>
		/// <param name="textureName"> 画像の名前 </param>
		/// <param name="pass">        通過可能か </param>
		AdventureObject(const Point& pos, const String& textureName, bool pass);

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="playerRegion"> プレイヤーの範囲 </param>
		/// <returns>
		/// 決定が押されたとき true , それ以外で false
		/// </returns>
		void update(const Rect& playerRegion);

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="cameraPos"> カメラの座標 </param>
		void draw(const Point& cameraPoint)const;

		/// <summary>
		/// 通過可能か true
		/// </summary>
		bool isPassing() const
		{
			return mIsPassing;
		}

		/// <summary>
		/// 決定押されたときの処理の設定
		/// </summary>
		/// <param name="func"> 処理 </param>
		void setOnClick(std::function<void()>& func)
		{
			mOnClick = func;
		}

	};
}
