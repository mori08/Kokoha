#pragma once


#include "Cassette/Cassette.h"


namespace Kokoha
{
	/*
	Equipmentクラス
	カセットの装備状況の管理
	効果の発動
	*/
	class Equipment
	{
	private:

		// 装備を使った時間
		double mUsedSecond;

		// 総コスト
		int32 mTotalCost;

		const int32 mCassetteState;

		// 装備しているカセットのリスト
		CassettePtrSet mCassetteList;

		// 発動待ちの効果のキュー(sortのためlistで実装)
		std::list<CassetteEffect> mEffectQueue;

	public:

		/// <summary>
		/// 装備
		/// </summary>
		/// <param name="state"> カセットに設定する状態 </param>
		Equipment(int32 state);

	public:

		// AdventureSceneで使用
		// ↓

		/// <summary>
		/// 全て削除
		/// </summary>
		/// <remarks>
		/// レコードの読み込み時以外で使わない
		/// </remarks>
		void clearCassette();

		/// <summary>
		/// カセットの追加
		/// </summary>
		/// <param name="cassette"> カセット </param>
		void addCassette(const CassettePtr& cassette);

		/// <summary>
		/// カセットの削除
		/// </summary>
		/// <param name="cassette"> カセット </param>
		void removeCassette(const CassettePtr& cassette);

		/// <summary>
		/// 装備カセットのリストの取得
		/// </summary>
		const CassettePtrSet& getCassetteList() const
		{
			return mCassetteList;
		}

		/// <summary>
		/// カセットの状態
		/// </summary>
		int32 getCassetteState()const
		{
			return mCassetteState;
		}

		/// <summary>
		/// カセットを追加できるかを示す
		/// </summary>
		/// <param name="cassette"> 追加したいカセット </param>
		bool isAddAbleCassette(const CassettePtr& cassette) const;

		/// <summary>
		/// 使用しているコストを取得
		/// </summary>
		const int32& getTotalCost() const
		{
			return mTotalCost;
		}

		// ↑
		// AdventureSceneで使用

	public:

		// GameSceneで使用
		// ↓

		/// <summary>
		/// mEffectQueueを装備状況に合わせて初期化
		/// </summary>
		void initEffect();

		/// <summary>
		/// mEffectQueueを更新
		/// </summary>
		void updateEffect();

		// ↑
		// GameSceneで使用

	};
}