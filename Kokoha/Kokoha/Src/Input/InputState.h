#pragma once


#include "Button.h"


namespace Kokoha
{
	using ButtonPtrMap = std::unordered_map<String, ButtonPtr>;

	/*
	InputStateクラス
	ButtonManagerで使用する入力の状態の基底
	*/
	class InputState
	{
	public:

		/// <summary>
		/// 決定の入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false </returns>
		/// </returns>
		virtual bool decesion() const = 0;

		/// <summary>
		/// キャンセルの入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false </returns>
		virtual bool cancel() const = 0;

		/// <summary>
		/// ボタンを選択します。
		/// </summary>
		/// <param name="selectedButtonPtr"> 選択中のボタン </param>
		/// <param name="buttonPtrMap">      ボタンのリスト </param>
		/// <returns> 
		/// 決定が入力されたときにそのボタンのキーを返します。
		/// 何も選択されていないとき無効値を返します。
		/// </returns>
		/// <remarks>
		/// 入力に応じたボタン選択の変更を行います。
		/// 1フレームに2度以上使用しないでください。
		/// ボタンが登録されていない状態で使用しないでください。
		/// </remarks>
		virtual Optional<String> selectButton(ButtonPtr& selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const = 0;

	};
}