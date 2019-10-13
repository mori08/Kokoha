#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	EventSceneクラス
	イベントを実行するシーン
	必ずLoadEventSceneから遷移する.
	*/
	class EventScene : public MyApp::Scene
	{
	public:

		EventScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}