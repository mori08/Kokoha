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

		// 装備カセット
		std::array<Equipment, EQUIPMENT_NUM> mEquipment;

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
		/// レコードからロード
		/// </summary>
		void load();

		/// <summary>
		/// カセットのリストの取得
		/// </summary>
		/// <returns>
		/// カセットのリスト
		/// </returns>
		const Array<CassettePtr>& getCassetteList() const
		{
			return mCassetteList;
		}

		/// <summary>
		/// 装備カセットの管理クラスの取得
		/// </summary>
		/// <param name="id"> 偶数なら装備A , 奇数なら装備B </param>
		/// <returns>
		/// 装備カセット
		/// </returns>
		Equipment& getEquipment(size_t id)
		{
			return mEquipment[id % EQUIPMENT_NUM];
		}

	};
}