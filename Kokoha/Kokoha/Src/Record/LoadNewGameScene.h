#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadNewGameSceneクラス
	レコードを初期化してはじめから始まる
	*/
	class LoadNewGameScene : public LoadScene
	{
	public:

		LoadNewGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}