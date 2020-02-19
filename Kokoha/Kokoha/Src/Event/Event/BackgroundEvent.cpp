#include "BackgroundEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 2;

	// インデックス
	constexpr size_t BACKGROUND_NAME = 0; // 背景画像の名前
	constexpr size_t INIT_CAMERA_POS = 1; // カメラの初期座標
}


bool Kokoha::BackgroundEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mBackgroundName = eventArg[BACKGROUND_NAME];

	if (!toPoint(mInitCameraPos, eventArg[INIT_CAMERA_POS])) { return false; }

	return true;
}


void Kokoha::BackgroundEvent::perform()
{
	EventManager::instance().setBackground(mBackgroundName);
	EventManager::instance().setCameraPos(mInitCameraPos);
}


bool Kokoha::BackgroundEvent::isCompleted() const
{
	return true;
}
