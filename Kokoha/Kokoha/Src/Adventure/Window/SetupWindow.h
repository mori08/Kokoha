#pragma once


#include "AdventureWindow.h"
#include "CassetteView/PossessCassetteView.h"
#include "CassetteView/EquipmentCassetteView.h"


namespace Kokoha
{
	/*
	SetupWindowクラス
	装備カセットの変更
	*/
	class SetupWindow : public AdventureWindow
	{
	private:

		// ボタンを指すカーソル {カーソル,目的座標}
		std::pair<RectF, Vec2> mCursor;

		// 選択中のボタン名
		String mSelectedButtonName;

		// 所持しているカセット一覧
		PossessCassetteView mPossessCassetteView;

		// 装備しているカセット一覧
		EquipmentCassetteView mEquipmentCassetteView;

	public:

		SetupWindow();

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}
