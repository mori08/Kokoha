#pragma once


#include <Siv3D.hpp>
#include "../../Scene.h"


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

		/// <summary>
		/// シーン遷移について
		/// </summary>
		/// <returns>
		/// 遷移しないとき none
		/// 遷移するとき   SceneName
		/// </returns>
		virtual Optional<SceneName> isChangeAbleScene() const
		{
			return none;
		}

	};

	using GameStatePtr = std::unique_ptr<GameState>;
}