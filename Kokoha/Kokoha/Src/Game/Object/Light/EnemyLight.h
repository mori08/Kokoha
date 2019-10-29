#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	EnemyLightクラス
	プレイヤーに一番近い敵を追跡
	*/
	class EnemyLight : public GameLight
	{
	private:

		// プレイヤーの座標
		Vec2 mPlayerPos;

		// 一番近い敵との最短距離
		double mMinDistance;

	public:

		EnemyLight(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

	};
}