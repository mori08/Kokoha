#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	PauseStateクラス
	一時停止の状態
	つづける・やりなおす・あきらめる の選択
	*/

	class PauseState : public GameState
	{
	private:

		// ポーズ前の状態
		std::unique_ptr<GameState> mPreState;

		// シーン名のopt, 遷移させないとき none
		Optional<SceneName> mSceneName;

		// カーソル
		RectF mCursor;

	public:

		PauseState(std::unique_ptr<GameState> preState);

	private:

		void update();

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const;

	};
}