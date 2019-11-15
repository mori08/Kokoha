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

		// 選択している装備の番号
		const int32 mSelectedEquipmentId;

		// カーソル
		RectF mCursor;

		// 選択しているボタン
		std::pair<Vec2, String> mSelectedButton;

	public:

		/// <summary>
		/// カセットを移動させるウィンドウ
		/// </summary>
		/// <param name="cassette"> カセット               </param>
		/// <param name="pos"     > 表示座標               </param>
		/// <param name="selected"> 選択している装備の番号 </param>
		CassetteMoveWindow(const CassettePtr& cassette, const Point& pos, int32 selected);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}