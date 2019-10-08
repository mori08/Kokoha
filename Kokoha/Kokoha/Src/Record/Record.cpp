#include "Record.h"


namespace
{
	// Œ…”‚ÌÅ‘å’l
	constexpr int32 MAX_DIGIT = 30;
}


Kokoha::Record::Record(int32 digit, int32 defaultValue)
	: mDigit(Max(1, Min(digit, MAX_DIGIT)))
	, mDefaultValue(Max(0, Min(defaultValue, (2 >> digit) - 1)))
	, mValue(mDefaultValue)
{
	
}


void Kokoha::Record::addRecordToEncryptionList(std::list<int>& dataList) const
{
	for (int i = 0; i < mDigit; ++i)
	{
		dataList.emplace_back((mValue >> i) & 1);
	}
}
