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
	EventManagerのコンストラクタに登録する
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
		virtual void perform() = 0;

		/// <summary>
		/// 終了しているか示す.
		/// </summary>
		/// <returns> 終了しているとき true , そうでないとき false </returns>
		virtual bool isCompleted() const = 0;


	protected: // load関数でのエラー確認

		/// <summary>
		/// 引数のサイズの確認
		/// </summary>
		/// <param name="argSize">       引数のサイズ </param>
		/// <param name="expectedValue"> 期待値       </param>
		/// <returns>
		/// 等しいとき true , そうでないとき false
		/// </returns>
		static bool checkArgSize(size_t argSize, size_t expectedValue);

		/// <summary>
		/// 文字列から二値への変換
		/// </summary>
		/// <param name="integer"> 変換後の二値の代入先 </param>
		/// <param name="str">     文字列               </param>
		/// <returns>
		/// 変換できたとき true , できなかったとき false
		/// </returns>
		static bool toBool(bool& flag, const String& str);

		/// <summary>
		/// 文字列から整数値への変換
		/// </summary>
		/// <param name="integer"> 変換後の整数値の代入先 </param>
		/// <param name="str">     文字列                 </param>
		/// <returns>
		/// 変換できたとき true , できなかったとき false
		/// </returns>
		static bool toInteger(int32& integer, const String& str);

		/// <summary>
		/// 文字列から小数値(double)への変換
		/// </summary>
		/// <param name="value"> 変換後の整数値の代入先 </param>
		/// <param name="str">   文字列                 </param>
		/// <returns>
		/// 変換できたとき true , できなかったとき false
		/// </returns>
		static bool toDouble(double& value, const String& str);

		/// <summary>
		// 文字列から座標への変換
		/// </summary>
		/// <param name="pos"> 変換後の座標の代入先  </param>
		/// <param name="str"> 文字列                </param>
		/// <returns>
		/// 変換できたとき true , できなかったとき false
		/// </returns>
		static bool toPoint(Point& pos, const String& str);

		/// <summary>
		/// オブジェクトがあるか確認
		/// </summary>
		/// <param name="name"> 名前 </param>
		/// <returns>
		/// オブジェクトがあったとき true , ないとき false
		/// </returns>
		static bool isExistedObject(const String& name);

	};
}