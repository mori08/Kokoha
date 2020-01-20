#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	RootingLightクラス
	道案内用ライト
	プレイヤーからゴールへ高速で向かう
	*/
	class RootingLight : public GameLight
	{
	public:

		/// <summary>
		/// 道案内用ライト
		/// </summary>
		/// <param name="eraseSecond"> 削除までの時間 </param>
		RootingLight(double eraseSecond);

	private:

		void checkAnother(const GameObject& another)override;

	};
}