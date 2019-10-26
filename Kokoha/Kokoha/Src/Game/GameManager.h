#pragma once


#include "StageData/StageData.h"
#include "Object/GameObject.h"


namespace Kokoha
{
	using GenerateGameObjectFunc = std::function<GameObjectPtr(const Vec2& pos)>;

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

		// オブジェクトのリスト
		std::list<GameObjectPtr> mObjectList;

		// オブジェクトを生成する関数の連想配列
		std::unordered_map<String, GenerateGameObjectFunc> mGenerateObjectMap;

	private:

		GameManager();

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

		/// <summary>
		/// ステージの取得
		/// </summary>
		/// <returns>
		/// ステージ
		/// </returns>
		const StageData& getStageData()const
		{
			return mStageData;
		}

	private:

		/// <summary>
		/// オブジェクトを作成する関数の登録
		/// </summary>
		/// <param name="name"> オブジェクトの名前 </param>
		template<typename ObjectType>
		void setGenerateObjectFunc(const String& name)
		{
			mGenerateObjectMap[name] = GenerateGameObjectFunc
			(
				[](const Vec2& pos)
				{
					return std::make_unique<ObjectType>(pos);
				}
			);
		}

	};
}