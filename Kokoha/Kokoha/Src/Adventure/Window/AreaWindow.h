#pragma once


#include "AdventureWindow.h"
#include "../../Input/ButtonManager.h"


namespace Kokoha
{
	/*
	AreaWindowクラス
	エリア移動用のウィンドウ
	*/
	class AreaWindow : public AdventureWindow
	{
	private:

		// ボタンのリスト
		Array<Button> mButtonList;

		// カーソル
		RectF mCursor;

	public:

		AreaWindow();

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}