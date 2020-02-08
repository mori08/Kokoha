#pragma once


#include "../GameObject.h"


namespace Kokoha
{
	/*
	GameHoleクラス
	WhiteEnemyを生成するオブジェクト
	*/
	class GameHole : public GameObject
	{
	public:

		// 輪の数
		static const int32 RING_NUM = 2;

	protected:

		// 目的座標
		Vec2 mGoal;

	private:

		// 輪がなす角度
		std::array<double, RING_NUM> mRingAngleList;

	public:

		GameHole(const Vec2& pos);

	private:

		void update() override;

		void draw() const override;

		void checkAnother(const GameObject&) override
		{
		}

	};
}