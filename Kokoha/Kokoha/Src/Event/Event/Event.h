#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	// イベントの引数
	using EventArg = std::vector<String>;

	/*
	Eventクラス
	csvファイルからイベントを読み込んだとき
	その1行分がこのクラスに対応する
	イベントの種類ごとにこのクラスの派生クラスを作成する

	このクラスの派生クラスを作るときは
	EventManagerのsetAllEvent関数に登録する
	*/
	class Event
	{
	public:

		/// <summary>
		/// 文字列の配列を受け取り、イベントの詳細を決定
		/// </summary>
		/// <param name="eventArg"> 文字列の配列 </param>
		/// <returns> 正しく決定できたとき true , そうでないとき false </returns>
		virtual bool load(const EventArg& eventArg) = 0;

		/// <summary>
		/// イベントの実行
		/// </summary>
		virtual void perform() const = 0;

		/// <summary>
		/// 終了しているか示す.
		/// </summary>
		/// <returns> 終了しているとき true , そうでないとき false </returns>
		virtual bool isCompleted() const = 0;

	};
}