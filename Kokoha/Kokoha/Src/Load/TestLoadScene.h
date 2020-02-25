#pragma once


#include "LoadScene.h"


namespace Kokoha
{
	/*
	TestLoadSceneクラス
	LoadSceneのテスト用
	*/
	class TestLoadScene : public LoadScene
	{
	private:

		int32 testNumber;

	public:

		TestLoadScene(const InitData& init)
			: LoadScene(init)
		{
		}

		ErrorMessage load() override;

		SceneName complete() override;

	};
}