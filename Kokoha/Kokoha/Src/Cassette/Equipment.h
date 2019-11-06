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

		// 装備しているカセットのリスト
		std::unordered_map<String, CassettePtr> mCassetteList;

		// 発動待ちの効果のキュー(sortのためlistで実装)
		std::list<CassetteEffect> mEffectQueue;

	public:

		Equipment();

	public:

		// AdventureSceneで使用
		// ↓

		/// <summary>
		/// カセットの追加
		/// </summary>
		/// <param name="cassette"> カセット </param>
		void addCassette(const CassettePtr& cassette);

		/// <summary>
		/// カセットの削除
		/// </summary>
		/// <param name="name"> カセット名 </param>
		void removeCassette(const String& name);

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