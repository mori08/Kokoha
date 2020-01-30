#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	ClearStateクラス
	プレイヤーがゴールしたときに遷移する状態
	*/
	class ClearState : public GameState
	{
	private:

		// 時間
		double mTimeSecond;

		// 背景のアルファ値
		double mBackAlpha;

		// 光のアルファ値
		double mLightAlpha;

		// 中心と光との距離
		double mRadius;

	public:

		ClearState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}