#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	RandomLightクラス
	ランダムに動く光
	*/
	class RandomLight : public GameLight
	{
	private:

		// 待ち時間
		double mWaitTime;

	public:

		/// <summary>
		/// ランダムに動く光
		/// </summary>
		/// <param name="radius"> 半径 </param>
		RandomLight(double radius);

	private:

		void update() override;

	};
}