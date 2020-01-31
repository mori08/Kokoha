#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*

	*/
	class GameOverState : public GameState
	{
	private:

		// 経過時間
		double mTimeSecond;

		// マスを表示するときのアルファ値
		double mSquareAlpha;

		// 遷移先のシーン
		Optional<SceneName> mSceneName;

		// カーソル
		RectF mCursor;

	public:

		GameOverState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}