#pragma once


#include "Cassette/Cassette.h"
#include "Equipment.h"


namespace Kokoha
{
	/*
	CassetteManagerクラス
	Cassetteを所持しているかの管理
	セットの変更
	*/
	class CassetteManager
	{
	public:

		// 装備カセットのセット数
		static constexpr int32 EQUIPMENT_NUM = 2;

	private:

		// カセットの集合
		Array<CassettePtr> mCassetteList;

		// 所持しているカセットの集合
		CassettePtrSet mPossessCassette;

		// 装備カセット
		std::array<Equipment, EQUIPMENT_NUM> mEquipment;

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

		/// <summary>
		/// 装備カセットの管理クラスの取得
		/// </summary>
		/// <param name="id"> 偶数なら装備A , 奇数なら装備B </param>
		/// <returns>
		/// 装備カセット
		/// </param>
		Equipment& getEquipment(size_t id)
		{
			return mEquipment[id % EQUIPMENT_NUM];
		}

	};
}