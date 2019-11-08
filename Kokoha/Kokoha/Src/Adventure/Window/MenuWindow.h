#pragma once


#include "AdventureWindow.h"
#include "../../Input/Button.h"


namespace Kokoha
{
	/*
	MenuWindowクラス
	メニュー
	Diary,Setup,Recordのウィンドウに遷移
	*/
	class MenuWindow : public AdventureWindow
	{
	private:

		// 選択中のボタン
		std::pair<Vec2, String> mSelectedButton;

		// 選択しているボタンを示す長方形
		RectF mCursor;

	public:

		/// <summary>
		/// メニュー用ウィンドウ
		/// </summary>
		MenuWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}