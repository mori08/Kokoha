#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	VirusBeetleHoleクラス
	高速に動く
	行ったことのない隣接マスを優先的に訪問する
	*/
	class VirusBeetleHole : public GameHole
	{
	private:

		// 現在いるマス
		Point mNowSquare;

		// 訪問回数を記録
		Array<int32> mVisitedCount;

	public:

		VirusBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}