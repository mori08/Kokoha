#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	StageMakingSceneクラス
	ステージの特徴を確認をするデバッグ用シーン
	追跡方向や逃走先を可視化する
	*/
	class CheckStageScene : public MyApp::Scene
	{
	public:

		CheckStageScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}