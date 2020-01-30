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

		const Vec2 LIGHT_SIZE;

		// 時間
		double mTimeSecond;

		// 背景のアルファ値
		double mAlpha;

		// 光
		std::array<RectF, 2> mLight;

	public:

		ClearState();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}