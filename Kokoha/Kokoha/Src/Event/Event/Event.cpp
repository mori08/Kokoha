#include "Event.h"
#include "../../MyLibrary.h"


bool Kokoha::Event::checkArgSize(size_t argSize, size_t expectedValue)
{
	if (argSize == expectedValue) { return true; }

	printDebug(U"[Event::checkArg]");
	printDebug(U"引数のサイズが違います.");
	printDebug(U"検出値 > " + argSize);
	printDebug(U"期待値 > " + expectedValue);

	return false;
}


bool Kokoha::Event::toInteger(int32& integer, const String& str)
{
	auto opt = ParseIntOpt<int32>(str);
	if (!opt) { return false; }

	integer = *opt;
	return true;
}
