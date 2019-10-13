#include "Event.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	EventManager::instance().addErrorMessage(U"[Event::checkArg]");
	EventManager::instance().addErrorMessage(U"引数のサイズが違います.");
	EventManager::instance().addErrorMessage(U"検出値 > " + argSize);
	EventManager::instance().addErrorMessage(U"期待値 > " + expectedValue);

	return false;
}


bool Kokoha::Event::toInteger(int32& integer, const String& str)
{
	auto opt = ParseIntOpt<int32>(str);
	if (!opt) 
	{ 
		EventManager::instance().addErrorMessage(U"[Event::toInteger]");
		EventManager::instance().addErrorMessage(U"整数値に変換できません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + str);
		return false; 
	}

	integer = *opt;
	return true;
}
