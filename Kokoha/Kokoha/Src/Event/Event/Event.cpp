#include "Event.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	EventManager::instance().addErrorMessage(U"[Event::checkArg]");
	EventManager::instance().addErrorMessage(U"引数のサイズが違います.");
	EventManager::instance().addErrorMessage(U"検出値 > " + ToString(argSize));
	EventManager::instance().addErrorMessage(U"期待値 > " + ToString(expectedValue));

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
	try
	{
		integer = Parse<int32>(str);
	}
	catch (const ParseError&)
	{
		EventManager::instance().addErrorMessage(U"[Event::toInteger]");
		EventManager::instance().addErrorMessage(U"整数値に変換できません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + str);
		return false;
	}

	return true;
}


bool Kokoha::Event::toDouble(double& value, const String& str)
{
	try
	{
		value = Parse<double>(str);
	}
	catch (const ParseError&)
	{
		EventManager::instance().addErrorMessage(U"[Event::toDouble]");
		EventManager::instance().addErrorMessage(U"小数値に変換できません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + str);
		return false;
	}

	return true;
}


bool Kokoha::Event::toPoint(Point& pos, const String& str)
{
	try
	{
		pos = Parse<Point>(str);
	}
	catch (const std::exception&)
	{
		EventManager::instance().addErrorMessage(U"[Event::toPoint]");
		EventManager::instance().addErrorMessage(U"座標に変換できません.");
		EventManager::instance().addErrorMessage(U"検出値 > " + str);
		return false;
	}

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
