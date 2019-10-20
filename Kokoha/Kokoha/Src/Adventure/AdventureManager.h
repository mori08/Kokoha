#pragma once


#include "AdventurePlayer.h"


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

	private:

		/// <summary>
		/// カメラ座標の変更
		/// </summary>
		void changeCameraPos();

	};
}