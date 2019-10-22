#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	AdventureWindowクラス
	AdventureManagerで表示するウィンドウ
	一番上に来る -> 選択
	*/
	class AdventureWindow
	{
	protected:

		// ウィンドウ背景
		const RoundRect mWindowBoard;

	public:

		/// <summary>
		/// ウィンドウ
		/// </summary>
		/// <param name="region"> ウィンドウの範囲 </param>
		AdventureWindow(const Rect& region);

		/// <summary>
		/// 選択した時の処理
		/// </summary>
		virtual void select() = 0;

		/// <summary>
		/// 更新
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// 選択時の更新
		/// </summary>
		virtual void selectedUpdate() = 0;

		/// <summary>
		/// 描画
		/// </summary>
		virtual void draw() const = 0;

	protected:

		/// <summary>
		/// ウィンドウ背景の描画
		/// </summary>
		void drawBoard() const;

	};

	using WindowPtr = std::unique_ptr<AdventureWindow>;
}