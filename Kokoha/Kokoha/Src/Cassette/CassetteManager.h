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

		// カセットの一覧
		Array<CassettePtr> mCassetteList;

		// 所持しているカセットの一覧
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

		static CassetteManager& instance()
		{
			static CassetteManager cassetteManager;
			return cassetteManager;
		}

	};
}