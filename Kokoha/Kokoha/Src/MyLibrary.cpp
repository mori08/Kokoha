#include "MyLibrary.h"


#ifdef _DEBUG
void Kokoha::printDebug(const String& message)
{
	Print << message;
}
#else
void Kokoha::printDebug(const String&)
{
	Print << message;
}
#endif // _DEBUG

