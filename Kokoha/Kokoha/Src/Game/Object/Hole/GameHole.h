#pragma once


#include "../GameObject.h"
#include "../../../Slice/SliceTexture.h"


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

		// 敵の生成間隔(s)
		Linearly<double> mGenerateSpan;

	private:

		SliceTexture mSlide;

	public:

		/// <summary>
		/// 白い敵を生成するオブジェクト
		/// </summary>
		/// <param name="pos"> 生成座標 </param>
		/// <param name="generateSpan"> 敵の生成間隔(s) </param>
		GameHole(const Vec2& pos, double generateSpan);

	protected:

		virtual void update() override;

		void draw() const override;

		void checkAnother(const GameObject&) override
		{
		}

	};
}