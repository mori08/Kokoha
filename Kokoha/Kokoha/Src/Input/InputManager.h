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
		static InputManager& instatnce();

		/// <summary>
		/// 決定の入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false
		/// </returns>
		bool decision() const;

		/// <summary>
		/// キャンセルの入力
		/// </summary>
		/// <returns>
		/// 入力された時 true , そうでないとき false
		/// </returns>
		bool cancel() const;

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