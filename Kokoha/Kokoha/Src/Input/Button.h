#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	class Button;
	using ButtonPtr     = std::shared_ptr<Button>;
	using ButtonOnClick = std::function<void()>;

	/*
	Buttonクラス
	主にButtonManagerで使用する.
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
		std::unordered_map<Direction, ButtonPtr> mAdjacentButtonMap;

		// 名前
		const String  mName;

		// 範囲
		const Rect    mRegion;

		// 押されたときの処理
		ButtonOnClick mOnClickFunc;

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
		void setAdjacentButton(const Direction& direction, ButtonPtr adjacentButtonPtr);

		/// <summary>
		/// 指定された方向に隣接するボタンのポインタの取得
		/// </summary>
		/// <param name="direction"> 方向 </param>
		/// <returns>
		/// 指定された方向に隣接するボタンのポインタ
		/// </returns>
		ButtonPtr getAdjacentButton(const Direction& direction) const;

		/// <summary>
		/// ボタンの名前を取得
		/// </summary>
		/// <returns>
		/// ボタンの名前
		/// </returns>
		const String& getName() const
		{
			return mName;
		}

		/// <summary>
		/// ボタンの範囲を取得
		/// </summary>
		/// <returns>
		/// ボタンの範囲
		/// </returns>
		const Rect& getRegion() const
		{
			return mRegion;
		}

		/// <summary>
		/// 押したときの処理の設定
		/// </summary>
		/// <param name="onClickFunc"> 押したときの処理 </param>
		void setOnClickFunc(const ButtonOnClick& onClickFunc)
		{
			mOnClickFunc = onClickFunc;
		}

		/// <summary>
		/// 押したときの処理
		/// </summary>
		void OnClick() const
		{
			mOnClickFunc();
		}

	};

}