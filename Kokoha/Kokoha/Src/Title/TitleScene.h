#pragma once


#include "../Scene.h"


namespace Kokoha
{
	/*
	TitleSceneクラス
	タイトルシーン
	ButtonManagerを使って他のシーンに遷移
	*/
	class TitleScene : public MyApp::Scene
	{
	private:

	public:

		TitleScene(const InitData& init);

		void update() override;

		void draw() const override;
	};
}