#pragma once


# include "../Scene.h"
# include <thread>
# include <future>
# include <utility>


namespace Kokoha
{
	// エラーメッセージ
	using ErrorMessage = Optional<String>;


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

		// ロード中に表示する文字列
		String mText;

		// ロードするスレッド
		std::thread mLoadThread;
		
		// エラーメッセージの取得
		std::future<ErrorMessage> mErrorMessageFuture;

	public:

		/// <summary>
		/// ロードを行うシーンの基底
		/// </summary>
		/// <param name="text">
		/// ロード中に表示するテキスト
		/// </param>
		LoadScene(const InitData& init,const String& text = U"Loading");

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
		/// <remarks>
		/// ロード中はゲームを終了させることができなくなるので
		/// 現実的な時間で終わる処理を書く.
		/// </remarks>
		virtual ErrorMessage load() = 0;

		/// <summary>
		/// スレッドの処理が終了したときに行う処理
		/// </summary>
		/// <returns>
		/// 遷移先のシーン
		/// </returns>
		virtual SceneName complete() = 0;

	};

}