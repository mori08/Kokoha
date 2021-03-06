#include "Record.h"


namespace
{
	// 桁数の最大値
	constexpr int32 MAX_DIGIT = 30;
}


int32 Kokoha::Record::sDigitTotal = 0;


Kokoha::Record::Record(int32 digit, int32 defaultValue)
	: mDigit(Max(1, Min(digit, MAX_DIGIT)))
	, mDefaultValue(Max(0, Min(defaultValue, (1 << digit) - 1)))
	, mValue(mDefaultValue)
{
	sDigitTotal += mDigit;
}


void Kokoha::Record::addRecordToEncryptionList(std::list<int32>& dataList) const
{
	for (int i = 0; i < mDigit; ++i)
	{
		dataList.emplace_back((mValue >> i) & 1);
	}
}


void Kokoha::Record::setValueFromDecryption(std::list<int32>& dataList)
{
	mValue = 0;

	for (int i = 0; i < mDigit; ++i)
	{
		if (dataList.empty())
		{
			return;
		}
		mValue |= dataList.front() << i;
		dataList.pop_front();
	}
}
