#pragma once


#include "Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteManagerクラス
	Cassetteを所持しているかの管理
	セットの変更
	*/
	class CassetteManager
	{
	private:

		// カセットの集合
		Array<CassettePtr> mCassetteList;

		// 所持しているカセットの集合
		CassettePtrSet mPossessCassette;

		// 速さ変更についてのキュー { 時間, 速さの倍率 }
		std::list<std::pair<double, double>> mChangeSpeedQueue;

	private:

		CassetteManager();

		CassetteManager(const CassetteManager&)            = default;
		CassetteManager& operator=(const CassetteManager&) = default;
		CassetteManager(CassetteManager&&)                 = default;
		CassetteManager& operator=(CassetteManager&&)      = default;

	public:

		/// <summary>
		/// シングルトンのインスタンスの取得
		/// </summary>
		static CassetteManager& instance()
		{
			static CassetteManager cassetteManager;
			return cassetteManager;
		}

	public:

		/// <summary>
		/// 所持カセットのリストを取得
		/// </summary>
		/// <returns>
		/// 所持カセットのリスト
		/// </returns>
		const CassettePtrSet& getPossessCassette()const
		{
			return mPossessCassette;
		}

	};
}