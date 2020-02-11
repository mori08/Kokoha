#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ShotHoleクラス
	プレイヤーに向かって白い敵を生成する
	*/
	class ShotHole : public GameHole
	{
	private:

		// ゴールの座標
		Vec2 mGoalPos;

		// プレイヤーの座標
		Vec2 mPlayerPos;

	public:

		ShotHole(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another);

	};
}