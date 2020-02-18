#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	ReloadGameSceneクラス
	GameManagerのreload関数を呼びます．
	*/
	class ReloadGameScene : public LoadScene
	{
	private:

		// ロードに成功したとき true, そうでないとき false
		bool mIsSuccess;

	public:

		ReloadGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}