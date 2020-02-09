#pragma once


#include "BlackEnemy.h"


namespace Kokoha
{
	/*
	ImitateEnemyクラス
	プレイヤーの動きをまねる敵
	WASDキーで移動
	*/
	class ImitateEnemy : public BlackEnemy
	{
	public:

		ImitateEnemy(const Vec2& pos);

	private:

		void update() override;

	};
}