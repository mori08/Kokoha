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

bool Kokoha::Event::toBool(bool& flag, const String& str)
{
	if (str == U"TRUE")  { flag = true;  return true; }
	if (str == U"FALSE") { flag = false; return true; }
	
	EventManager::instance().addErrorMessage(U"[Event::toBool]");
	EventManager::instance().addErrorMessage(U"二値に変換できません.");
	EventManager::instance().addErrorMessage(U"検出値 > " + str);

	return false;
}


bool Kokoha::Event::toInteger(int32& integer, const String& str)
{
	auto opt = ParseOpt<int32>(str);
	if (!opt) 
	{ 
		EventManager::instance().addErrorMessage(U"[Event::toInteger]");
		EventManager::instance().addErrorMessage(U"整数値に変換できません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + str);
		return false; 
	}

	integer = opt.value();
	return true;
}


double Kokoha::Event::toDouble(double& value, const String& str)
{
	return true;
}


bool Kokoha::Event::isExistedObject(const String& name)
{
	if (!EventManager::instance().getObjectPtr(name))
	{
		EventManager::instance().addErrorMessage(U"[Event::isExistedObject]");
		EventManager::instance().addErrorMessage(U"指定されたオブジェクトが存在しません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + name);
		return false;
	}

	return true;
}
