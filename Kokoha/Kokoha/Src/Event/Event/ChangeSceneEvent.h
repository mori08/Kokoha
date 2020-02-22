#pragma once


#include "Event.h"
#include "../../Scene.h"


namespace Kokoha
{
	/*
	ChangeSceneEventクラス
	シーン遷移先イベント
	*/
	class ChangeSceneEvent : public Event
	{
	private:

		// シーン名のマップ
		static std::unordered_map<String, SceneName> sSceneNameMap;

		// シーン遷移先
		SceneName mSceneName;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	public:

		/// <summary>
		/// シーン名のマップの設定
		/// </summary>
		static void setSceneNameMap();

	};
}