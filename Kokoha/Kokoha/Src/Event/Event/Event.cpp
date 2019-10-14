#include "Event.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	EventManager::instance().addErrorMessage(U"[Event::checkArg]");
	EventManager::instance().addErrorMessage(U"�����̃T�C�Y���Ⴂ�܂�.");
	EventManager::instance().addErrorMessage(U"���o�l > " + ToString(argSize));
	EventManager::instance().addErrorMessage(U"���Ғl > " + ToString(expectedValue));

	return false;
}


bool Kokoha::Event::toBool(bool& flag, const String& str)
{
	if (str == U"TRUE")  { flag = true;  return true; }
	if (str == U"FALSE") { flag = false; return true; }
	
	EventManager::instance().addErrorMessage(U"[Event::toBool]");
	EventManager::instance().addErrorMessage(U"��l�ɕϊ��ł��܂���.");
	EventManager::instance().addErrorMessage(U"���o�l > " + str);

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
		EventManager::instance().addErrorMessage(U"�����l�ɕϊ��ł��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + str);
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
		EventManager::instance().addErrorMessage(U"�����l�ɕϊ��ł��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + str);
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
		EventManager::instance().addErrorMessage(U"���W�ɕϊ��ł��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + str);
		return false;
	}

	return true;
}


bool Kokoha::Event::isExistedObject(const String& name)
{
	if (!EventManager::instance().getObjectPtr(name))
	{
		EventManager::instance().addErrorMessage(U"[Event::isExistedObject]");
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�I�u�W�F�N�g�����݂��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + name);
		return false;
	}

	return true;
}
