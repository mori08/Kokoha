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

		void load() override;

		void complete() override;

	};
}