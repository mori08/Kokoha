#pragma once


#include "../Load/LoadScene.h"
#include "RecordManager.h"


namespace Kokoha
{
	/*
	LoadRecordScene�N���X
	���R�[�h��RECORD.txt���烍�[�h����.
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