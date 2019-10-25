#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	GameSceneクラス
	ステージを攻略するシーン
	必ずLoadGameSceneから遷移する.
	*/
	class GameScene : public MyApp::Scene
	{
	public:

		GameScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}