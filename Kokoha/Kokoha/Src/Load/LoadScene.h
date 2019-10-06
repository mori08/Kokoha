#pragma once


#include "../Scene.h"
#include <thread>


namespace Kokoha
{
	/*
	LoadSceneクラス
	時間のかかる処理を別スレッドで行うシーン
	処理の内容はload関数, 終了時の処理はcomplete関数を
	オーバーロードして派生クラスを作成する
	*/
	class LoadScene : public MyApp::Scene
	{
	private:

		// ロード中のとき true , 終了したとき false
		bool mIsLoading;

	protected:

		// ロードするスレッド
		std::thread mLoadThread;

	public:

		LoadScene(const InitData& init);

		virtual ~LoadScene();

	private:

		void update() override;

		virtual void draw() const override;

		void drawFadeIn(double) const override;

		void drawFadeOut(double) const override;

	protected:

		/// <summary>
		/// mLoadThreadで動かす関数
		/// </summary>
		virtual void load() = 0;

		/// <summary>
		/// スレッドの処理が終了したときに行う処理
		/// </summary>
		/// <remarks>
		/// 必ずシーン遷移を行う
		/// </remarks>
		virtual void complete() = 0;

	};

}