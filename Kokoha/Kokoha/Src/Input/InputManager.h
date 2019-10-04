#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	InputManagerクラス
	マウス・キーボードの入力の切り替えを行い,
	決定,キャンセルの入力を確認します.
	*/
	class InputManager
	{
	private:

		// 入力方法についての状態
		std::unique_ptr<InputState> mInputState;

	private:

		InputManager();

		InputManager(const InputManager&)            = default;
		InputManager& operator=(const InputManager&) = default;
		InputManager(InputManager&&)                 = default;
		InputManager& operator=(InputManager&&)      = default;

	public:

		/// <summary>
		/// シングルトンとして管理しているInputManagerのインスタンスの取得
		/// </summary>
		/// <returns>
		/// インスタンス
		/// </returns>
		static InputManager& instatnce()
		{
			static InputManager inputManager;
			return inputManager;
		}

		/// <summary>
		/// 決定の入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false
		/// </returns>
		bool decision() const
		{
			return mInputState->decesion();
		}

		/// <summary>
		/// キャンセルの入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false
		/// </returns>
		bool cancel() const
		{
			return mInputState->cancel();
		}

		/// <summary>
		/// ボタンを選択
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
		Optional<String> selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const
		{
			return mInputState->selectButton(selectedButtonPtr, buttonPtrMap);
		}

		/// <summary>
		/// 入力の状態を変更します
		/// </summary>
		/// <remarks>
		/// ループの最初で使用
		/// 1ループに1度だけ
		/// </remarks>
		void changeInputState();

	};
}