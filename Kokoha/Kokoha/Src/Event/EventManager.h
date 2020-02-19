#pragma once


#include "Event/Event.h"
#include "Object/EventObject.h"
#include "TextBox/TextBox.h"
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

		// イベント名
		String mEventFileName;

		// イベントを管理するキュー
		std::queue<EventPtr> mEventQueue;

		// イベントを生成する関数の連想配列
		std::unordered_map<String, MakeEventFunc> mMakeEventMap;

		// オブジェクトと文字列の連想配列
		std::map<String, EventObjectPtr> mObjectMap;

		// テキストボックス
		TextBox mTextBox;

		// 背景の画像名
		String mBackgroundName;

		// カメラ座標
		Linearly<Vec2> mCameraPos;

		// ロードのエラーメッセージ
		String mErrorMessage;

	private:

		EventManager();

		EventManager(const EventManager&)            = default;
		EventManager& operator=(const EventManager&) = default;
		EventManager(EventManager&&)                 = default;
		EventManager& operator=(EventManager&&)      = default;

	public: 
		
		// Sceneクラスの派生で使用
		// ↓

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
		/// イベント名の設定
		/// </summary>
		/// <param name="eventName"> 対応するステージ名 </param>
		void setEventFileName(const String& stageName)
		{
			mEventFileName = U"Assets/Data/Event/Event(" + stageName + U").csv";
		}

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// イベントを記述したcsvファイルの読み込み
		/// </summary>
		/// <returns>
		/// 成功したとき true, 失敗したとき false
		/// </returns>
		bool load()
		{
			return load(mEventFileName);
		}

		/// <summary>
		/// イベントを記述したcsvファイルの読み込み
		/// </summary>
		/// <param name="eventFileName"> イベントのファイル名 </param>
		/// <returns>
		/// 成功したとき true, 失敗したとき false
		/// </returns>
		bool load(const String& eventFileName);

		/// <summary>
		/// エラーメッセージの追加
		/// </summary>
		/// <param name="str"> 追加する文字列 </param>
		void addErrorMessage(const String& str)
		{
			mErrorMessage += str + U"\n";
		}

		/// <summary>
		/// エラーメッセージの取得
		/// </summary>
		/// <returns>
		/// エラーメッセージ
		/// </returns>
		const String& getErrorMessage()
		{
			return mErrorMessage;
		}

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

		// ↑
		// Sceneクラスの派生で使用

	public:

		// Eventクラスの派生で使用
		// ↓

		/// <summary>
		/// オブジェクトの生成
		/// </summary>
		/// <param name="name">   名前         </param>
		/// <param name="object"> オブジェクト </param>
		void generateObject(const String& name, EventObjectPtr&& object)
		{
			mObjectMap.try_emplace(name, std::move(object));
		}

		/// <summary>
		/// オブジェクトのポインタを取得
		/// </summary>
		/// <param name="name"> 名前 </param>
		/// <returns>
		/// オブジェクトのポインタ
		/// 名前に対応したオブジェクトがないとき nullptr
		/// </returns>
		EventObjectPtr& getObjectPtr(const String& name)
		{
			return mObjectMap[name];
		}

		/// <summary>
		/// 背景の設定
		/// </summary>
		/// <param name="backgroundName"> 背景画像の名前 </param>
		void setBackground(const String& backgroundName)
		{
			mBackgroundName = backgroundName;
		}

		/// <summary>
		/// カメラの移動の設定
		/// </summary>
		/// <param name="time"    > 移動時間(秒) </param>
		/// <param name="movement"> 移動量       </param>
		void setCameraMove(double time,const Point& movement);

		/// <summary>
		/// カメラの座標の設定
		/// </summary>
		/// <param name="pos"> 次の座標 </param>
		void setCameraPos(const Point& pos)
		{
			mCameraPos = Linearly<Vec2>(0, pos, Vec2::Zero());
		}

		/// <summary>
		/// テキストボックスの取得
		/// </summary>
		/// <returns>
		/// テキストボックス
		/// </returns>
		/// <remarks>
		/// const参照じゃありません.
		/// EventManagerとTextEvent以外では使わないでください.
		/// </remarks>
		TextBox& getTextBox()
		{
			return mTextBox;
		}

		// ↑
		// Eventクラスの派生で使用

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