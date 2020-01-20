#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	GoalLightクラス
	ゴールを照らす光
	*/
	class GoalLight : public GameLight
	{
	private:

		// true のときルート案内用の光を生成する
		bool mIsRooting;

		// 案内用の光を出すまでの時間
		double mRootingSecond;

	public:

		/// <summary>
		/// ゴールを照らすライト
		/// </summary>
		/// <param name="radius"     > 半径               </param>
		/// <param name="eraseSecond"> 削除する時間       </param>
		/// <param name="isRooting"  > ルート案内をするか </param>
		GoalLight(double radius, double eraseSecond, bool isRooting);

	private:

		void update()override;

		void checkAnother(const GameObject& another)override;

	};
}