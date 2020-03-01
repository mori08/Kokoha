#include "EffectEvent.h"
#include "../EventManager.h"


namespace
{
	// 引数サイズ
	constexpr size_t ARG_SIZE = 1;

	// インデックス
	constexpr size_t NAME = 0; // 名前
}


bool Kokoha::EffectEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mEffectName = eventArg[NAME];
	if (mEffectName == U"Dark" || mEffectName == U"Noise")
	{
		return true;
	}

	EventManager::instance().addErrorMessage(U"[EffectEvent::load]");
	EventManager::instance().addErrorMessage(U"指定されたエフェクトが存在しません");
	EventManager::instance().addErrorMessage(U"エフェクト名 > " + mEffectName);
	return false;
}


void Kokoha::EffectEvent::perform()
{
	EventManager::instance().setEffect(mEffectName);
}


bool Kokoha::EffectEvent::isCompleted() const
{
	return true;
}
