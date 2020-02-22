#pragma once


#include "../GameState.h"


namespace Kokoha
{
	/*
	AwakeStateクラス
	Tutorial終了後の状態
	*/
	class AwakeState : public GameState
	{
	private:

		// 時間
		double mTimeSecond;

		// 背景のアルファ値
		double mBackAlpha;

	public:

		AwakeState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}