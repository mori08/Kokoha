#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Cassetteクラス
	装備品のような扱いをし,
	セットアップ画面やステージで扱う
	*/
	class Cassette
	{
	private:

		// 使われているか
		bool mUsed;

	public:

		// 名前
		const String NAME;

		// コスト
		const int32 COST;

		// 効果時間(秒) { 開始,終了 }
		const std::pair<double, double> TERM;

		// 効果
		const std::function<void()> EFFECT;

	public:

		/// <summary>
		/// カセット
		/// </summary>
		/// <param name="name"  > 名前                    </param>
		/// <param name="cost"  > コスト                  </param>
		/// <param name="term"  > 効果時間(秒){開始,終了} </param>
		/// <param name="effect"> 効果                    </param>
		Cassette(const String& name, int32 cost, const std::pair<double, double>& term, const std::function<void()>& effect);

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
		bool getUsed()
		{
			return mUsed;
		}

	};
}