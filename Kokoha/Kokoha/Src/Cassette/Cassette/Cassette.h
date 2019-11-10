#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	CassetteEffectクラス
	カセットの効果の管理
	発動時間と行う処理のまとめ
	*/
	class CassetteEffect
	{
	public:

		// 開始時間(秒)
		const double BEGIN_SECOND;

		// 処理(カセットの効果)
		const std::function<void()> EFFECT_FUNCTION;

	public:

		CassetteEffect(double beginSecond, const std::function<void()>& func)
			: BEGIN_SECOND(beginSecond)
			, EFFECT_FUNCTION(func)
		{
		}

		bool operator<(const CassetteEffect& another)const
		{
			return BEGIN_SECOND < another.BEGIN_SECOND;
		}

	};


	/*
	Cassetteクラス
	装備品のような扱いをし,
	セットアップ画面やステージで扱う
	*/
	class Cassette
	{
	private:

		// カセットの種類数
		static int32 sNum;

		// カセット番号(ソート用)
		const int32 ID;

		// 使われているか
		bool mUsed;

	public:

		// 名前
		const String NAME;

		// コスト
		const int32 COST;

		// カセットの効果
		const CassetteEffect EFFECT;

	public:

		/// <summary>
		/// 空カセット
		/// </summary>
		Cassette()
			: ID(Inf<int32>)
			, NAME(U"")
			, COST(0)
			, EFFECT(0, [](){})
		{
		}

		/// <summary>
		/// カセット
		/// </summary>
		/// <param name="name"  > 名前               </param>
		/// <param name="cost"  > コスト             </param>
		/// <param name="term"  > 効果の開始時間(秒) </param>
		/// <param name="effect"> 効果               </param>
		Cassette(const String& name, int32 cost, const CassetteEffect& cassetteEffect);

		/// <summary>
		/// 番号の比較
		/// </summary>
		bool operator<(const Cassette& another)
		{
			return ID < another.ID;
		}

		/// <summary>
		/// 使用中かどうかの切り替え
		/// </summary>
		/// <param name="used"> true なら使用中 , falseなら未使用 </param>
		void setUsed(bool used)
		{
			mUsed = used;
		}

		/// <summary>
		/// 使用中か
		/// </summary>
		/// <returns> true なら使用中 , falseなら未使用 </returns>
		bool getUsed()const
		{
			return mUsed;
		}

		/// <summary>
		/// 効果の取得
		/// </summary>
		/// <returns>
		/// 効果
		/// </returns>
		const CassetteEffect& getEffect()const
		{
			return EFFECT;
		}

		/// <summary>
		/// スピードカセットの効果の作成
		/// </summary>
		/// <param name="speed"> 速さの倍率 </param>
		/// <param name="term" > 効果時間   </param>
		static CassetteEffect&& makeSpeedEffect(double speed, const std::pair<double, double>& term);

	};


	using CassettePtr = std::shared_ptr<Cassette>;


	/*
	CompareCassettePtr構造体
	CassettePtrの大小比較をCassetteのIDで行う
	*/
	struct CompareCassettePtr
	{
		bool operator()(const CassettePtr& ptrA, const CassettePtr& ptrB)const
		{
			return *ptrA < *ptrB;
		}
	};


	using CassettePtrSet = std::set<CassettePtr, CompareCassettePtr>;

}