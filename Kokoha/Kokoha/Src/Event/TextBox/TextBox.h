#pragma once


#include "../../Slice/Linearly.h"


namespace Kokoha
{ 
	/*
	TextBoxクラス
	テキスト・アイコンの表示
	*/
	class TextBox
	{
	private:

		// 話し手の名前
		String mSpeakerName;

		// アイコンの画像の名前
		String mIconName;

		// 表示できるテキストの長さ
		Linearly<double> mDrawAbleLength;

		// テキスト
		String mText;

		// 次のテキストが設定できるか
		bool mIsReady;

	public:

		TextBox();

		/// <summary>
		/// 初期化
		/// </summary>
		void reset();

		/// <summary>
		/// 表示するテキストなどの設定
		/// </summary>
		/// <param name="speakerName"> 話し手の名前        </param>
		/// <param name="iconName">    アイコン名          </param>
		/// <param name="drawSpan">    1文字を描画する時間 </param>
		/// <param name="text">        テキスト            </param>
		void set(const String& speakerName, const String& iconName, double drawSpan, const String& text);

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

		/// <summary>
		/// 新しいテキストを設定できるか示す
		/// </summary>
		/// <returns>
		/// 可能なら true , 不可能なら false
		/// </returns>
		bool isReady() const
		{
			return mIsReady;
		}

	};

}