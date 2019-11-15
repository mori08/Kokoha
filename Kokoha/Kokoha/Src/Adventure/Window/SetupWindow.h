#pragma once


#include "AdventureWindow.h"
#include "CassetteView/CassetteView.h"


namespace Kokoha
{
	/*
	SetupWindowクラス
	装備カセットの変更
	*/
	class SetupWindow : public AdventureWindow
	{
	private:

		// 選択している装備の番号
		int32 mSelectedEquipmentId;

		// ボタンを指すカーソル
		RectF mCursor;

		// 所持しているカセット一覧
		CassetteView mPossessCassetteView;

		// 装備しているカセット一覧
		CassetteView mEquipmentCassetteView;

		// 選択中のボタン
		String mSelectedButtonName;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
