#include "GenerateEvent.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"

// イベントオブジェクト
#include "../Object/TestEventObject.h"


namespace
{
	// 引数のサイズ
	constexpr size_t ARG_SIZE = 3;

	// インデックス
	constexpr size_t TYPE = 0; // オブジェクトの種類
	constexpr size_t NAME = 1; // オブジェクトの名前
	constexpr size_t POS  = 2; // 生成座標
}


std::unordered_map<String, Kokoha::GenerateEventObjectFunc> Kokoha::GenerateEvent::sGenerateObjectMap;


bool Kokoha::GenerateEvent::load(const EventArg& eventArg)
{
	if (!checkArgSize(eventArg.size(), ARG_SIZE)) { return false; }

	mType = eventArg[TYPE];
	if (!sGenerateObjectMap.count(mType))
	{
		EventManager::instance().addErrorMessage(U"[GenerateEvent::load]");
		EventManager::instance().addErrorMessage(U"指定されたオブジェクトの型が登録されてません.");
		EventManager::instance().addErrorMessage(U"型名 > " + mType);
		return false;
	}

	mName = eventArg[NAME];

	if (!toPoint(mPos,eventArg[POS])) { return false; }

	return true;
}


void Kokoha::GenerateEvent::perform()
{
	EventManager::instance().generateObject(mName, sGenerateObjectMap[mType](mPos));
}


bool Kokoha::GenerateEvent::isCompleted() const
{
	return true;
}


void Kokoha::GenerateEvent::setAllGenerateObjectFunc()
{
	setGenerateObjectFunc<TestEventObject>(U"Test");
}
