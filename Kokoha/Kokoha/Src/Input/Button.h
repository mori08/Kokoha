#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Buttonクラス
	主にInputManagerで使用する.
	*/
	class Button
	{
	public:

		enum class Direction
		{
			UP,   // 上
			DOWN, // 下
			LEFT, // 左
			RIGHT // 右
		};

	private:

		// 隣接ボタンのマップ
		std::unordered_map<Direction, std::shared_ptr<Button>> mAdjacentButtonMap;

		// 名前
		const String mName;

		// 範囲
		const Rect   mRegion;

	public:

		/// <summary>
		/// ボタン
		/// </summary>
		/// <param name="name">   名前 </param>
		/// <param name="region"> 範囲 </param>
		Button(const String& name, const Rect& region);

	public:

		/// <summary>
		/// 隣接するボタンを設定
		/// </summary>
		/// <param name="direction">         方向                     </param>
		/// <param name="adjacentButtonPtr"> 隣接するボタンのポインタ </param>
		void setAdjacentButton(const Direction& direction, std::shared_ptr<Button> adjacentButtonPtr);

		/// <summary>
		/// 指定された方向に隣接するボタンのポインタの取得
		/// </summary>
		/// <param name="direction"> 方向 </param>
		/// <returns>
		/// 指定された方向に隣接するボタンのポインタ
		/// </returns>
		std::shared_ptr<Button> getAdjacentButton(const Direction& direction);

		/// <summary>
		/// ボタンの名前を取得
		/// </summary>
		const String& getName() const;

		/// <summary>
		/// ボタンの範囲を取得
		/// </summary>
		const Rect& getRegion() const;

	};

}