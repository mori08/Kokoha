#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	AdventureSceneクラス
	部屋を探索するシーン
	必ずLoadAdventureSceneから遷移する.
	*/
	class AdventureScene : public MyApp::Scene
	{
	public:

		AdventureScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}