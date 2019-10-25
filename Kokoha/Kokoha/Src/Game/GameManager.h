#pragma once


#include "StageData/StageData.h"


namespace Kokoha
{
	/*
	GameManagerクラス
	CSVファイルからゲームデータを読み込み
	GameObject・StageDataの管理
	*/
	class GameManager
	{
	private:

		// ステージ
		StageData mStageData;

	private:

		GameManager()
		{

		}

		GameManager(const GameManager &)             = default;
		GameManager & operator=(const GameManager &) = default;
		GameManager(GameManager &&)                  = default;
		GameManager & operator=(GameManager &&)      = default;

	public:

		/// <summary>
		/// シングルトンとして管理しているGameManagerのインスタンスの取得
		/// </summary>
		/// <returns> シングルトン </returns>
		static GameManager& instance()
		{
			static GameManager gameManager;
			return gameManager;
		}

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// ゲームデータを記述したcsvファイルの読み込み
		/// </summary>
		/// <param name="fileName"> csvファイルのファイル名 </param>
		/// <returns>
		/// エラーメッセージ
		/// </returns>
		Optional<String> load(const String& fileName);

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

	};
}