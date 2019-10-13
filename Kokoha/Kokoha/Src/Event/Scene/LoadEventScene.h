#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadEventSceneクラス
	イベントが記述されたCSVファイルを読み込みます.
	*/
	class LoadEventScene : public LoadScene
	{
	private:

		// ロードに成功したとき true , そうでないとき false
		bool mIsScuccess;

	public:

		LoadEventScene(const InitData& init);

	private:

		void load() override;

		void complete() override;

	};
}