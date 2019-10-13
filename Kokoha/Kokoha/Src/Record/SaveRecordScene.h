#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	SaveRecordSceneクラス
	レコードをRECORD.txtにセーブする.
	*/
	class SaveRecordScene : public LoadScene
	{
	public:

		SaveRecordScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}