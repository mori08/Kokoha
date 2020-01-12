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
	public:

		// 所持していない
		static constexpr int32 NO_POSSESS_STATE = 0;

		// 所持
		static constexpr int32 POSSESS_STATE = 1;

		// 装備 A
		static constexpr int32 EQUIPMENT_A_STATE = 2;

		// 装備 B
		static constexpr int32 EQUIPMENT_B_STATE = 3;		

	private:

		// カセットの種類数
		static int32 sNum;

		// カセット番号(ソート用)
		const int32 ID;

		// 状態
		int32 mState;

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
			, mState(NO_POSSESS_STATE)
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
		/// 状態の切り替え
		/// </summary>
		/// <param name="state"> 状態 </param>
		void setState(int32 state)
		{
			mState = state;
		}

		/// <summary>
		/// 状態の取得
		/// </summary>
		/// <returns> 状態 </returns>
		int32 getState()const
		{
			return mState;
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
		/// アイコン画像の取得
		/// </summary>
		TextureRegion getIconTexture()const
		{
			static const Size SIZE(60, 60); // ボタンの幅
			return TextureAsset(U"CassetteIcon")(ID * SIZE.x, 0, SIZE);
		}

		/// <summary>
		/// スピードカセットの効果の作成
		/// </summary>
		/// <param name="speed"> 速さの倍率 </param>
		/// <param name="term" > 効果時間   </param>
		static CassetteEffect makeSpeedEffect(double speed, const std::pair<double, double>& term);

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