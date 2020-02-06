#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	InfoStateクラス
	ステージをクリアしたことによって
	起こる変化を表示
	*/
	class InfoState : public GameState
	{
	public:

		using AreaFlag = Optional<String>;

		// 情報のまとめ
		class Info
		{
		public:

			// カセット
			const Optional<int> CASSETTE_ID;

			// ステージ
			const std::function<AreaFlag()> AREA_FLAG_FUNC;

			Info()
				: CASSETTE_ID(none)
				, AREA_FLAG_FUNC([]() { return none; })
			{
			}

			Info(const Optional<int>& cassetteId, const std::function<AreaFlag()>& areaFlag)
				: CASSETTE_ID   (cassetteId)
				, AREA_FLAG_FUNC(areaFlag)
			{
			}
		};

	private:

		// ステージごとの表示情報
		static std::unordered_map<String, Info> sInfoMap;

		// 経過時間(s)
		double mTimeSecond;

		// 表示するテキストのリスト
		Array<String> mTextList;

		// テキストを表示するX座標
		double mDrawTextPosX;

		// 黒色のアルファ値
		double mAlpha;

	public:

		InfoState();

		/// <summary>
		/// マップにInfoを設定
		/// </summary>
		static void setInfoMap();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}