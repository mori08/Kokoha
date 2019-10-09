#pragma once


#include "Event/Event.h"
#include <queue>


namespace Kokoha
{
	// イベントのポインタ
	using EventPtr = std::unique_ptr<Event>;
	
	// イベントを生成する関数
	using MakeEventFunc = std::function<EventPtr()>;


	/*
	EventManagerクラス
	CSVファイルからのEventの読み込みや実行
	EventObjectの管理
	*/
	class EventManager
	{
	private:

		// イベントを管理するキュー
		std::queue<EventPtr> mEventQueue;

		// イベントを生成する関数の連想配列
		std::unordered_map<String, MakeEventFunc> mMakeEventMap;

	private:

		EventManager();

		EventManager(const EventManager&)            = default;
		EventManager& operator=(const EventManager&) = default;
		EventManager(EventManager&&)                 = default;
		EventManager& operator=(EventManager&&)      = default;

	public:

		/// <summary>
		/// シングルトンとして管理しているEventManagerのインスタンスの取得
		/// </summary>
		/// <returns>
		/// インスタンス
		/// </returns>
		static EventManager& instance()
		{
			static EventManager eventManager;
			return eventManager;
		}

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// イベントを記述したcsvファイルの読み込み
		/// </summary>
		/// <param name="eventFileName"> csvファイルの名前 </param>
		/// <returns>
		/// 成功したとき true, 失敗したとき false
		/// </returns>
		bool load(const String& eventFileName);

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

	private:

		/// <summary>
		/// イベントの登録
		/// </summary>
		/// <param name="name"> イベント名 </param>
		template<typename eventType>
		void setEvent(const String& name)
		{
			mMakeEventMap[name] = MakeEventFunc
			(
				[]()
				{
					return std::move(std::make_unique<eventType>());
				}
			);
		}

		/// <summary>
		/// mEventQueue内の全イベントを実行
		/// </summary>
		/// <remarks>
		/// 初期化用に行います。
		/// isCompleted関数での判定待ちは行いません.
		/// </remarks>
		void runAllEvent();

	};

}