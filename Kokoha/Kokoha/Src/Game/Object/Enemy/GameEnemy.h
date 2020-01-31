#pragma once


#include "../GameObject.h"
#include "../../../Slice/SliceTexture.h"


namespace Kokoha
{
	/*
	GameEnemyクラス
	GameManagerで使用する敵オブジェクト
	*/
	class GameEnemy : public GameObject
	{
	private:

		// true のときライトをつける
		static bool sOnLight;

		// 光の半径
		static double sLightRadius;

		// 光を表示する時間
		static double sLightSecond;

	private:

		// 体の画像とアニメーション
		SliceTexture mBodySlide;

		// 顔の画像とアニメーション
		SliceTexture mFaceSlide;

		// 光のアルファ値
		double mLightAlpha;

	public:

		/// <summary>
		/// 敵
		/// </summary>
		/// <param name="pos"        > 座標   </param>
		/// <param name="type"       > 種類   </param>
		/// <param name="textureName"> 画像名 </param>
		GameEnemy(const Vec2& pos,const ObjectType& type, const String& textureName);

		virtual void update() override;

		virtual void draw()const override;

		void drawLight()const override;

		void checkAnother(const GameObject& another) override;

	public:

		/// <summary>
		/// 敵の場所を示す光をつける
		/// </summary>
		/// <param name="radius"> 半径             </param>
		/// <param name="second"> 光を表示する時間 </param>
		static void lightOn(double radius, double second);

		/// <summary>
		/// 敵の場所を示す光を消す
		/// </summary>
		static void lightOff();

		/// <summary>
		/// 敵の場所を示す光の更新
		/// </summary>
		static void lightUpdate();

	};
}


#include "BlackEnemy.h"
#include "WhiteEnemy.h"