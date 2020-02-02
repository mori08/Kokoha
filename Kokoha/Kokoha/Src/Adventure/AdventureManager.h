#pragma once


#include "AdventurePlayer.h"
#include "Window/AdventureWindow.h"
#include "../Scene.h"


namespace Kokoha
{
	/*
	AdventureManagerクラス
	CSVファイルから部屋データを読み込み
	AdventureObject, Windowの管理
	*/
	class AdventureManager
	{
	private:

		// プレイヤー
		AdventurePlayer mPlayer;

		// 部屋の幅
		int32 mRoomWidth;

		// オブジェクトのリスト
		Array<AdventureObject> mObjectList;

		// カメラ座標
		Point mCameraPos;

		// ウィンドウ
		std::list<WindowPtr> mWindowList;

		// エリア番号
		int32 mAreaId;

		// シーン遷移先
		Optional<SceneName> mSceneName;

	private:

		AdventureManager();

		AdventureManager(const AdventureManager&)            = default;
		AdventureManager& operator=(const AdventureManager&) = default;
		AdventureManager(AdventureManager&&)                 = default;
		AdventureManager& operator=(AdventureManager&&)      = default;

	public:

		static AdventureManager& instance()
		{
			static AdventureManager adventureManager;
			return adventureManager;
		}

		/// <summary>
		/// 部屋のロード
		/// </summary>
		/// <param name="fileName"> ファイル名 </param> 
		Optional<String> load();

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw()const;

	public:

		/// <summary>
		/// ウィンドウを開く
		/// </summary>
		/// <param name="window"> 開くウィンドウ </param>
		void openWindow(WindowPtr&& window)
		{
			mWindowList.emplace_back(std::move(window));
			mWindowList.back()->select();
		}

		/// <summary>
		/// 一番上のウィンドウを閉じる
		/// </summary>
		void closeWindow();

		/// <summary>
		/// 全ウィンドウを閉じる
		/// </summary>
		void clearWindow();

		/// <summary>
		/// エリアの設定
		/// </summary>
		/// <param name="areaId"> エリアの番号 </param>
		void setAreaId(int32 areaId)
		{
			mAreaId = areaId;
		}

		/// <summary>
		/// エリアの取得
		/// </summary>
		/// <returns> エリアの番号 </returns>
		int32 getAreaId() const
		{
			return mAreaId;
		}

		/// <summary>
		/// シーン遷移先の設定
		/// </summary>
		/// <param name="sceneName"> シーン名 </param>
		void setSceneName(const SceneName& sceneName)
		{
			mSceneName = sceneName;
		}

		/// <summary>
		/// シーン遷移先の設定
		/// </summary>
		/// <param name="none_t"> シーン名 </param>
		void setSceneName(const None_t& none_t)
		{
			mSceneName = none_t;
		}

		/// <summary>
		/// シーン遷移先の取得
		/// </summary>
		/// <returns> シーン名 </returns>
		const Optional<SceneName>& getSceneName() const
		{
			return mSceneName;
		}

	private:

		/// <summary>
		/// カメラ座標の変更
		/// </summary>
		void changeCameraPos();

	};
}