#pragma once


#include "../Scene.h"


namespace Kokoha
{
	/*
	EndingSceneクラス
	玄関ゲートクリア時に遷移するシーン
	*/
	class EndingScene : public MyApp::Scene
	{
	private:

		// エンディングの名前
		String mEndingName;

	public:

		EndingScene(const InitData& init);

	private:

		void update() override;

		void draw() const override;

	};
}