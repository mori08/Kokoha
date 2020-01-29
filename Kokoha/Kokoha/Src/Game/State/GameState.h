#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	GameStateクラス
	GameManagerでの状態を示す
	派生クラスを作って状態遷移する
	*/
	class GameState
	{
	public:

		/// <summary>
		/// 更新
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// 描画
		/// </summary>
		virtual void draw() const = 0;

	};

	using GameStatePtr = std::unique_ptr<GameState>;
}