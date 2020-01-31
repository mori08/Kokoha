#pragma once


#include "StageData/StageData.h"
#include "Object/GameObject.h"
#include "PlayerSpeed/PlayerSpeed.h"
#include "State/GameState.h"


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

		// ステージ名
		String mName;

		// オブジェクトのリスト
		std::list<GameObjectPtr> mObjectList;

		// 追加オブジェクトのリスト
		std::list<GameObjectPtr> mAddObjectList;

		// オブジェクトを生成する関数の連想配列
		std::unordered_map<String, GenerateGameObjectFunc> mGenerateObjectMap;

		// 選択している装備のID
		int32 mEquipmentId;

		// プレイヤーの速さ
		PlayerSpeed mPlayerSpeed;

		// プレイヤーの座標
		Vec2 mPlayerPos;

		// 状態(GameSceneでの更新・描画について)
		GameStatePtr mState;

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
		/// 状態の取得
		/// </summary>
		/// <returns> 状態 </returns>
		GameStatePtr& getState()
		{
			return mState;
		}

		/// <summary>
		/// 状態の設定
		/// </summary>
		/// <param name="state"> 状態 </param>
		void setState(GameStatePtr state)
		{
			mState = std::move(state);
		}
		
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// ステージ名の設定
		/// </summary>
		/// <param name="name"> ステージ名 </param>
		void setName(const String& name)
		{
			mName = name;
		}

		/// <summary>
		/// ゲームデータを記述したcsvファイルの読み込み
		/// </summary>
		/// <param name="stageName"> ステージ名 </param>
		/// <returns>
		/// エラーメッセージ
		/// </returns>
		Optional<String> load();

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

		/// <summary>
		/// プレイヤーの速さの取得
		/// </summary>
		/// <returns>
		/// プレイヤーの速さ
		/// </returns>
		double getPlayerSpeed()const
		{
			return mPlayerSpeed.get();
		}

		/// <summary>
		/// 選択中の装備のＩＤを取得
		/// </summary>
		int32 getEquipmentId()const
		{
			return mEquipmentId;
		}

		/// <summary>
		/// プレイヤーの速さの変更の設定
		/// </summary>
		/// <param name="speedRate"> 速さの倍率 </param>
		/// <param name="term"     > 期間       </param>
		void setSpeedChange(double speedRate, const std::pair<double, double>& term)
		{
			mPlayerSpeed.change(speedRate, term.second);
		}

		/// <summary>
		/// プレイヤーの座標の設定
		/// </summary>
		/// <param name="pos"> プレイヤーの座標 </param>
		void setPlayerPos(const Vec2& pos)
		{
			mPlayerPos = pos;
		}

		/// <summary>
		/// プレイヤーの座標の取得
		/// </summary>
		/// <returns>
		/// プレイヤーの座標
		/// </returns>
		const Vec2& getPlayerPos()const
		{
			return mPlayerPos;
		}

		/// <summary>
		/// オブジェクトの追加
		/// </summary>
		/// <param name="objectPtr"> オブジェクトのポインタ </param>
		void addObject(GameObjectPtr&& objectPtr)
		{
			mAddObjectList.emplace_back(std::move(objectPtr));
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

		/// <summary>
		/// 装備カセットの切り替え
		/// </summary>
		void changeEquipment();

	};
}