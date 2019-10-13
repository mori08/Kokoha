#include "EventManager.h"
#include "../MyLibrary.h"

// 各イベント
#include "Event/EmptyEvent.h"
#include "Event/GenerateEvent.h"


namespace 
{
	constexpr int32 EVENT_NAME_COLUMN = 0;     // CSVファイル中のイベントの名前を記述する列数
	constexpr int32 EVENT_ARG_COLUMN  = 1;     // CSVファイル中のイベントの詳細を最初に記述する列数
	const String EVENT_ARG_END  = U"#";        // CSVファイル中でイベントの詳細の最後に使う文字列
	const String RUN_EVENT_KEY  = U"Run";      // CSVファイル中で登録済みのイベントを全て実行する命令
	const String FUNC_EVENT_KEY = U"Function"; // CSVファイル中で別CSVファイルのイベントを読み込む命令
}


Kokoha::EventManager::EventManager()
{
	// イベントの登録
	setEvent<GenerateEvent>(U"Generate");

	GenerateEvent::setAllGenerateObjectFunc();
}


void Kokoha::EventManager::init()
{
	// イベントのキューを空にします
	while (!mEventQueue.empty()) { mEventQueue.pop(); }

	// 空イベントをキューに入れます
	mEventQueue.push(std::make_unique<EmptyEvent>());
}


bool Kokoha::EventManager::load(const String& eventFileName)
{	
	CSVData csv(eventFileName);
	if (csv.isEmpty())
	{
		printDebug(U"[EventManger::load]");
		printDebug(eventFileName + U" を読み込めませんでした.");
		return false;
	}

	for (int32 loadingRow = 0; loadingRow < csv.rows(); ++loadingRow)
	{
		// イベントの名前の取得
		String eventName = csv[loadingRow][EVENT_NAME_COLUMN];

		// 現在キューにある全イベントを実行
		if (eventName == RUN_EVENT_KEY)
		{
			runAllEvent();
			continue;
		}

		// 別CSVファイルの読み込み
		if (eventName == FUNC_EVENT_KEY)
		{
			String funcName = csv[loadingRow][EVENT_ARG_COLUMN];
			if (!load(funcName))
			{
				printDebug(eventFileName + U" : " + ToString(loadingRow + 1) + U"行目");
				return false;
			}
			continue;
		}
		
		// イベントがあるかを確認
		if (!mMakeEventMap.count(eventName))
		{
			printDebug(U"イベント<" + eventName + U">は存在しません.");
			printDebug(eventFileName + U" : " + ToString(loadingRow + 1) + U"行目");
			return false;
		}

		// イベントの詳細の作成
		EventArg eventArg;
		for (int32 column = EVENT_ARG_COLUMN;; ++column)
		{
			// 終了文字が見つからないときエラー
			if (column >= csv.columns(loadingRow))
			{
				printDebug(U"終了文字 " + EVENT_ARG_END + U" がありません.");
				printDebug(eventFileName + U" : " + ToString(loadingRow + 1) + U"行目");
				return false;
			}

			// 終了文字の確認
			if (csv[loadingRow][column] == EVENT_ARG_END) { break; }
			
			// 詳細に追加
			eventArg.emplace_back(csv[loadingRow][column]);
		}
		
		// イベントのポインタの生成
		EventPtr eventPtr = mMakeEventMap[eventName]();
		
		// イベントの詳細の読み込み
		if (!eventPtr->load(eventArg))
		{
			printDebug(eventFileName + U" : " + ToString(loadingRow + 1) + U"行目");
			return false;
		}
		
		// キューにイベントを追加
		mEventQueue.push(std::move(eventPtr));
	}

	return true;
}


void Kokoha::EventManager::update()
{
	// イベントの更新
	if (mEventQueue.size() > 1 && mEventQueue.front()->isCompleted())
	{
		mEventQueue.pop();
		mEventQueue.front()->perform();
	}
}


void Kokoha::EventManager::draw() const
{

}


void Kokoha::EventManager::runAllEvent()
{
	while (mEventQueue.empty())
	{
		mEventQueue.front()->perform();
		mEventQueue.pop();
	}

	mEventQueue.push(std::make_unique<EmptyEvent>());
}
