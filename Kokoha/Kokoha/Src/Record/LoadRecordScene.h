#pragma once


#include "../Load/LoadScene.h"
#include "RecordManager.h"


namespace Kokoha
{
	/*
	LoadRecordSceneクラス
	レコードをRECORD.txtからロードする.
	*/
	class LoadRecordScene : public LoadScene
	{
	private:

		RecordManager::LoadResult mLoadResult;

	public:

		LoadRecordScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}