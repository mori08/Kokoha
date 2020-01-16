#pragma once


#include "AdventureWindow.h"
#include "../../Cassette/Cassette/Cassette.h"
#include "../../Input/Button.h"


namespace Kokoha
{
	/*
	CassetteMoveWindowクラス
	カセットを動かすウィンドウ
	カセットの状態によって操作が異なる
	*/
	class CassetteMoveWindow : public AdventureWindow
	{
	private:

		// カセットのポインタ
		CassettePtr mCassettePtr;

		// ボタンのリスト
		Array<Button> mButtonList;

		// 文字のアルファ値
		std::unordered_map<String, int32> mAlphaMap;

		// カーソル
		RectF mCursor;

		// 選択しているボタン
		std::pair<Vec2, String> mSelectedButton;

	public:

		/// <summary>
		/// カセットを移動させるウィンドウ
		/// </summary>
		/// <param name="cassette"> カセット </param>
		/// <param name="pos"     > 表示座標 </param>
		CassetteMoveWindow(const CassettePtr& cassette, const Point& pos);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}