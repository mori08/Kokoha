#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	TextEventクラス
	テキストボックスにテキストなどを設定
	*/
	class TextEvent : public Event
	{
	private:

		// 話し手の名前
		String mSpeakerName;

		// アイコン名
		String mIconName;

		// 1文字表示する時間
		double mSpanSecond;

		// テキスト
		String mText;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}