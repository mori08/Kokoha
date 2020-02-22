#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	RewardWindowクラス
	ステージのクリア報酬の表示を行う
	*/
	class RewardWindow : public AdventureWindow
	{
	private:

		// 報酬まとめ
		class Reward
		{
		public:

			// カセットID
			const Optional<int32> CASSETTE_ID;

			// ステージ
			const std::function<Optional<String>()> AREA_FLAG_FUNC;

			Reward()
				: CASSETTE_ID(none)
				, AREA_FLAG_FUNC([]() { return none; })
			{
			}

			Reward(const Optional<int32> cassetteId, const std::function<Optional<String>()>& areaFlagFunc)
				: CASSETTE_ID(cassetteId)
				, AREA_FLAG_FUNC(areaFlagFunc)
			{
			}
		};

	private:

		// ステージごとの表示情報
		static std::unordered_map<String, Reward> sRewardMap;

		// 表示するテキストのリスト
		Array<String> mTextList;

	public:

		/// <summary>
		/// 報酬を表示するウィンドウ
		/// </summary>
		/// <param name="stageName"> ステージ名 </param>
		RewardWindow(const String& stageName);

		/// <summary>
		/// マップに報酬を設定
		/// </summary>
		static void setRewardMap();

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}