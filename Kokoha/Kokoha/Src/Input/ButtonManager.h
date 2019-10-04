#pragma once


#include "InputManager.h"


namespace Kokoha
{
	/*
	ButtonManagerクラス
	Buttonの管理・選択を行います.
	*/
	class ButtonManager
	{
	private:

		// 管理しているボタンの連想配列
		ButtonPtrMap mButtonMap;

		// 選択中のボタン
		ButtonPtr    mSelectedButtonPtr;

	private:

		ButtonManager();

		ButtonManager(const ButtonManager&)            = default;
		ButtonManager& operator=(const ButtonManager&) = default;
		ButtonManager(ButtonManager&&)                 = default;
		ButtonManager& operator=(ButtonManager&&)      = default;

	public:

		/// <summary>
		/// シングルトンとして管理しているButtonManagerのインスタンスの取得
		/// </summary>
		/// <returns>
		/// インスタンス
		/// </returns>
		static ButtonManager& instance()
		{
			static ButtonManager buttonManager;
			return buttonManager;
		}

		/// <summary>
		/// ボタンの登録
		/// </summary>
		/// <param name="name">   ボタンの名前 </param>
		/// <param name="region"> ボタンの範囲 </param>
		void registerButton(const String& name, const Rect& region);

		/// <summary>
		/// ボタンの登録
		/// </summary>
		/// <param name="button"> ボタン </param>
		void registerButton(ButtonPtr button);

		/// <summary>
		/// ボタンの垂直方向の隣接関係の設定
		/// </summary>
		/// <param name="upName">   上側のボタンの名前 </param>
		/// <param name="downName"> 下側のボタンの名前 </param>
		void setVerticalAdjacentButton(const String& upName, const String& downName);

		/// <summary>
		/// ボタンの水平方向の隣接関係の設定
		/// </summary>
		/// <param name="leftName">  左側のボタンの名前 </param>
		/// <param name="rightName"> 右側のボタンの名前 </param>
		void setHorizontalAdjacentButton(const String& leftName, const String& rightName);

		/// <summary>
		/// 選択中のボタンの変更
		/// </summary>
		/// <param name="name"> ボタンの名前 </param>
		void setSelectedButton(const String& name);

		/// <summary>
		/// 選択中のボタンの取得
		/// </summary>
		/// <returns>
		/// 選択中のボタン
		/// </returns>
		const Button& getSelectedButton() const
		{
			return *mSelectedButtonPtr;
		}

		/// <summary>
		/// ボタンのリストを空にします
		/// </summary>
		void clearButtonList();

		/// <summary>
		/// ボタンの選択
		/// </summary>
		/// <returns>
		/// 決定が入力されたときそのボタンの名前を返します.
		/// 何も選択されていないとき無効値を返します.
		/// </returns>
		/// <remarks>
		/// 入力に応じたボタン選択の変更を行います。
		/// 1フレームに2度以上使わないでください。
		/// </remarks>
		Optional<String> selectButton()
		{
			return InputManager::instatnce().selectButton(mSelectedButtonPtr, mButtonMap);
		}

	};
}