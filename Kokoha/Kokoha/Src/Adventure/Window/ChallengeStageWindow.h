#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	ChallengeStageWindowクラス
	ステージに挑戦するか確認するウィンドウ
	*/
	class ChallengeStageWindow : public AdventureWindow
	{
	private:

		// ステージ名
		const String mStageName;

		// カーソル
		RectF mCursor;

		// カーソルの移動先
		std::pair<Vec2, String> mSelectedButton;

		// ステージのレベル
		static std::unordered_map<String, int32> sLevel;

	public:

		ChallengeStageWindow(const String& stageName);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	public:

		/// <summary>
		/// ステージのレベルの設定
		/// </summary>
		static void setLevel();

	};
}