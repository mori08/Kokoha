#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	ChaseHoleクラス
	プレイヤーを追跡する白い敵を生成する
	*/
	class ChaseHole : public GameHole
	{
	public:

		ChaseHole(const Vec2& pos);

	private:

		void update() override;

	};
}