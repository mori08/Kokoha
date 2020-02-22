#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialMoveStateクラス
	移動方法の説明
	*/
	class TutorialMoveState : public TutorialState
	{
	private:

		// プレイヤーの座標
		Vec2 mPlayerPos;

		// 移動距離
		double mMoveDistance;

	public:

		TutorialMoveState();

	private:

		void update() override;

		void draw() const override;

	};
}