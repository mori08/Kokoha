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

		// 体の画像とアニメーション
		SliceTexture mBodySlide;

		// 顔の画像とアニメーション
		SliceTexture mFaceSlide;

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

	};
}


#include "BlackEnemy.h"
#include "WhiteEnemy.h"