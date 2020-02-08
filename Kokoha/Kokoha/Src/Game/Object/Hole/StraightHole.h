#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	StraightHoleクラス
	StraightWhiteEnemyを定期的に生成する
	引数を使って方向を指定
	*/
	class StraightHole : public GameHole
	{
	private:

		// 生成する敵の移動量
		const Vec2 mEnemyMovement;

	public:

		StraightHole(const Vec2& pos, const Vec2& direction);

	private:

		void update();

	};


	class UpHole : public StraightHole
	{
	public:
		UpHole(const Vec2& pos) : StraightHole(pos, Vec2::Up()) {}
	};

	class RightHole : public StraightHole
	{
	public:
		RightHole(const Vec2& pos) : StraightHole(pos, Vec2::Right()) {}
	};

	class DownHole : public StraightHole
	{
	public:
		DownHole(const Vec2& pos) : StraightHole(pos, Vec2::Down()) {}
	};

	class LeftHole : public StraightHole
	{
	public:
		LeftHole(const Vec2& pos) : StraightHole(pos, Vec2::Left()) {}
	};
}