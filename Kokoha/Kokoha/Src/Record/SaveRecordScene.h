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

		void load() override;

		void complete() override;

	};
}