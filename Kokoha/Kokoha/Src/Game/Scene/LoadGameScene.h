#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadGameSceneクラス
	GameManagerのload関数を呼びます.
	*/
	class LoadGameScene : public LoadScene
	{
	private:

		// ロードに成功したとき true , そうでないとき false
		bool mIsSuccess;

	public:

		LoadGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}