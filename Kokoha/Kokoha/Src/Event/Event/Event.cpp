#include "Event.h"
#include "../../MyLibrary.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	printDebug(U"[Event::checkArg]");
	printDebug(U"�����̃T�C�Y���Ⴂ�܂�.");
	printDebug(U"���o�l > " + argSize);
	printDebug(U"���Ғl > " + expectedValue);

	return false;
}


bool Kokoha::Event::toInteger(int32& integer, const String& str)
{
	auto opt = ParseIntOpt<int32>(str);
	if (!opt) { return false; }

	integer = *opt;
	return true;
}
