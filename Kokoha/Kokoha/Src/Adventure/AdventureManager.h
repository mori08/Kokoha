#pragma once


#include "AdventurePlayer.h"
#include "Window/AdventureWindow.h"


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
		Optional<String> load(const String& fileName);

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
		void openWindow(WindowPtr& window)
		{
			mWindowList.emplace_back(std::move(window));
		}

		/// <summary>
		/// 一番上のウィンドウを閉じる
		/// </summary>
		void closeWindow();

	private:

		/// <summary>
		/// カメラ座標の変更
		/// </summary>
		void changeCameraPos();

	};
}