#pragma once


#include "Event.h"
#include "../Object/EventObject.h"


namespace Kokoha
{
	// イベントオブジェクトを生成する関数
	using GenerateEventObjectFunc = std::function<EventObjectPtr(const Point& pos)>;

	/*
	GenerateEventクラス
	EventObjectを生成し,
	EventManagerのmObjectMapに追加
	イベントのCSVデータではRunより前に記述
	*/
	class GenerateEvent : public Event
	{
	private:

		// オブジェクトを生成する関数のマップ
		static std::unordered_map<String, GenerateEventObjectFunc> sGenerateObjectMap;

		// 生成するオブジェクトの種類
		String mType;

		// 生成するオブジェクトの名前
		String mName;

		// オブジェクトを生成する座標
		Point mPos;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	public:

		/// <summary>
		/// オブジェクトを生成する関数を全てマップに登録
		/// </summary>
		static void setAllGenerateObjectFunc();

	private:

		/// <summary>
		/// オブジェクトを生成する関数をマップに登録
		/// </summary>
		/// <param name="name"> オブジェクトの型名 </param>
		template<typename eventObjectType>
		static void setGenerateObjectFunc(const String& name)
		{
			sGenerateObjectMap[name] = GenerateEventObjectFunc
			(
				[](const Point& pos)
				{
					return std::make_unique<eventObjectType>(pos);
				}
			);
		}

	};
}