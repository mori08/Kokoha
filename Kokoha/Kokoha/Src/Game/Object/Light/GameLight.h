#pragma once


#include "../GameObject.h"
#include <limits>


namespace Kokoha
{
	/*
	GameLightクラス
	GameManagerで扱う光
	drawLightに#F0F0F0で描画
	*/
	class GameLight : public GameObject
	{
	protected:

		// 光の目的地
		Vec2 mGoal;

		// 移動の速さ
		const double mSpeed;

		// 削除するまでの時間(秒)
		double mEraseSecond;

	public:

		/// <summary>
		/// 光
		/// </summary>
		/// <param name="body"       > 光の範囲     </param>
		/// <param name="speed"      > 速さ         </param>
		/// <param name="eraseSecond"> 削除する時間 </param>
		GameLight(const Circle& body, double speed, double eraseSecond = std::numeric_limits<double>::infinity());

	private:

		virtual void update() override;

		virtual void draw() const override
		{
		}

		virtual void drawLight() const override;

		virtual bool isEraseAble() const override;

	};
}
