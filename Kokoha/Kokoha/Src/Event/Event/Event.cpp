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


bool Kokoha::Event::toInteger(int32& integer, const String& str)
{
	auto opt = ParseIntOpt<int32>(str);
	if (!opt) 
	{ 
		EventManager::instance().addErrorMessage(U"[Event::toInteger]");
		EventManager::instance().addErrorMessage(U"�����l�ɕϊ��ł��܂���.");
		EventManager::instance().addErrorMessage(U"���o�l > " + str);
		return false; 
	}

	integer = *opt;
	return true;
}
