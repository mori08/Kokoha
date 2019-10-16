#include "TextEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 4;

	// インデックス
	constexpr size_t SPEAKER = 0; // 話し手の名前
	constexpr size_t ICON    = 1; // アイコン
	constexpr size_t SPAN    = 2; // 一文字を表示する時間
	constexpr size_t TEXT    = 3; // テキスト
}


bool Kokoha::TextEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mSpeakerName = eventArg[SPEAKER];
	mIconName    = eventArg[ICON];

	if (!toDouble(mSpanSecond, eventArg[SPAN])) { return false; }

	mText = eventArg[TEXT];

	return true;
}


void Kokoha::TextEvent::perform()
{
	EventManager::instance().getTextBox().set(mSpeakerName, mIconName, mSpanSecond, mText);
}


bool Kokoha::TextEvent::isCompleted() const
{
	return EventManager::instance().getTextBox().isReady();
}
