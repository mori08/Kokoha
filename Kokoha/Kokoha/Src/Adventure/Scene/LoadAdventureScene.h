#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadAdventureSceneクラス
	AdventureManagerのload関数を呼びます.
	*/
	class LoadAdventureScene : public LoadScene
	{
	private:

		// ロードに成功したとき true , そうでないとき false
		bool mIsSuccess;

	public:

		LoadAdventureScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}