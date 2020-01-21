#pragma once


#include "../GameObject.h"
#include "../../../Slice/SliceTexture.h"


namespace Kokoha
{
	/*
	GameGoalクラス
	ゴールの基底となるクラス
	*/
	class GameGoal : public GameObject
	{
	protected:

		// 目的地
		Vec2 mGoal;

		// 速さ
		const double mSpeed;

		// 画像とアニメーション
		SliceTexture mSlide;

	public:

		GameGoal(const Vec2& pos, double speed = 0.0);

	protected:

		virtual void update()override;

		void draw()const override;

		void checkAnother(const GameObject& another)override;

	};
}