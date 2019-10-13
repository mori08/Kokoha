#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadRecordSceneクラス
	レコードをRECORD.txtからロードする.
	*/
	class LoadRecordScene : public LoadScene
	{
	public:

		LoadRecordScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}