#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	PlayingStateクラス
	ステージを遊ぶときの状態
	*/
	class PlayingState : public GameState
	{
	private:

		void update() override;

		void draw()const override;

	};
}