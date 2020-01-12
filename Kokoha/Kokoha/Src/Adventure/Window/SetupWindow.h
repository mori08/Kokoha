#pragma once


#include "AdventureWindow.h"
#include "CassetteView/PossessCassetteView.h"


namespace Kokoha
{
	/*
	SetupWindowクラス
	装備カセットの変更
	*/
	class SetupWindow : public AdventureWindow
	{
	private:

		// ボタンを指すカーソル
		RectF mCursor;

		// 選択中のボタン名
		String mSelectedButtonName;

		// 所持しているカセット一覧
		PossessCassetteView mPossessCassetteView;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
