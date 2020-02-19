#include "BackgroundEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 1;

	// インデックス
	constexpr size_t BACKGROUND_NAME = 0; // 背景画像の名前
}


bool Kokoha::BackgroundEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mBackgroundName = eventArg[BACKGROUND_NAME];

	return true;
}


void Kokoha::BackgroundEvent::perform()
{
	EventManager::instance().setBackground(mBackgroundName);
}


bool Kokoha::BackgroundEvent::isCompleted() const
{
	return true;
}
