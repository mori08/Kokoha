#include "Event.h"
#include "../../MyLibrary.h"
#include "../EventManager.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	EventManager::instance().addErrorMessage(U"[Event::checkArg]");
	EventManager::instance().addErrorMessage(U"�����̃T�C�Y���Ⴂ�܂�.");
	EventManager::instance().addErrorMessage(U"���o�l > " + argSize);
	EventManager::instance().addErrorMessage(U"���Ғl > " + expectedValue);

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
	auto opt = ParseOpt<int32>(str);
	if (!opt) 
	{ 
		EventManager::instance().addErrorMessage(U"[Event::toInteger]");
		EventManager::instance().addErrorMessage(U"�����l�ɕϊ��ł��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + str);
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
		EventManager::instance().addErrorMessage(U"�w�肳�ꂽ�I�u�W�F�N�g�����݂��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + name);
		return false;
	}

	return true;
}
