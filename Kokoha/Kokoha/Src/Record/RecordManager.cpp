#include "RecordManager.h"
#include "../MyLibrary.h"
#include "../Cassette/CassetteManager.h"


namespace
{
	// ���R�[�h��ۑ�����t�@�C����
	const String RECORD_TEXT_NAME = U"Assets/Data/RECORD.txt";

	constexpr int32 BASE    = 0x10;      // �Í����̊�ɂȂ�l(���i���ňÍ������邩)
	constexpr int32 MUL     = BASE - 1;  // �|���Z�̂Ƃ��̂����鐔
	constexpr int32 HALF    = BASE / 2;  // ��l�̔���
	constexpr int32 MOD     = BASE*BASE; // �]����Ƃ�Ƃ��̊��鐔 
	constexpr int32 MAX_KEY = MOD - 1;   // ���̍ő�l

	// �Í����ɂ�����1�f�[�^�̂Ƃ镶����
	constexpr int32 ONE_DATA_LENGTH = 2;
}


Kokoha::RecordManager::RecordManager()
{
	mRecordMap.try_emplace(U"TestFlag" , std::move(Record(1, 1)));
	mRecordMap.try_emplace(U"TestValue", std::move(Record(3, 5)));

	// Adventure�ł̃v���C���[�̈ʒu
	mRecordMap.try_emplace(U"AreaId"         , std::move(Record(3, 0)));
	mRecordMap.try_emplace(U"PlayerPos"      , std::move(Record(11, 382)));
	mRecordMap.try_emplace(U"PlayerDirection", std::move(Record(1, 1)));

	// �X�e�[�W�̃N���A��
	mRecordMap.try_emplace(U"Tutorial", std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"1-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"1-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"1-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"2-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"2-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"2-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"3-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"3-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"3-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"4-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"4-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"4-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"5-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"5-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"5-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"6-1"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"6-2"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"6-3"     , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"Kokoro"  , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"Last"    , std::move(Record(1, 0)));

	// �J�Z�b�g
	mRecordMap.try_emplace(U"CassetteCapacity", std::move(Record(3, 6)));
	for (const auto& cassette : CassetteManager::instance().getCassetteList())
	{
		if (cassette->NAME == U"�X�s�[�hI" || cassette->NAME == U"�v���C���[I")
		{
			/*
				���������J�Z�b�g�͏������l���Ⴄ���߂����ł̓X�L�b�v
				�ʂɃ��R�[�h�ɓo�^����
			*/
			continue;
		}

		mRecordMap.try_emplace(cassette->NAME, std::move(Record(2, Cassette::NO_POSSESS_STATE)));
	}
	mRecordMap.try_emplace(U"�X�s�[�hI"  , std::move(Record(2, Cassette::EQUIPMENT_A_STATE)));
	mRecordMap.try_emplace(U"�v���C���[I", std::move(Record(2, Cassette::EQUIPMENT_B_STATE)));
}


Kokoha::RecordManager::LoadResult Kokoha::RecordManager::load()
{
	TextReader reader(RECORD_TEXT_NAME);

	// RECORD.txt�����݂��Ȃ��Ƃ� NEWGAME
	if (!reader.isOpened())
	{
		initAllRecord();
		return LoadResult::NEW_GAME;
	}

	String line;

	if (reader.readLine(line) && decryption(line))
	{
		return LoadResult::CONTINUE;
	}

	return LoadResult::ERROR;
}


void Kokoha::RecordManager::initAllRecord()
{
	for (auto& record : mRecordMap)
	{
		record.second.init();
	}
}


void Kokoha::RecordManager::save()
{
	TextWriter writer(RECORD_TEXT_NAME);

	writer.write(encryption());
}


void Kokoha::RecordManager::printAllRecord()
{
	ClearPrint();
	int32 cnt = 0;
	String text;
	for (auto& record : mRecordMap)
	{
		text += U"[" + record.first + U" : " + ToString(record.second.get()) + U"]";
		
		if (++cnt % 3 == 0) { Print << text; text = U""; }
	}
}


void Kokoha::RecordManager::setRecord(const String& name, int32 value)
{
	if (!mRecordMap.count(name)) 
	{ 
		printDebug(U"[RecordManager::setRecord]");
		printDebug(U"�o�^����Ă��Ȃ����R�[�h�ł�");
		printDebug(U"name > " + name);
		return; 
	}

	mRecordMap.find(name)->second.set(value);
}


int32 Kokoha::RecordManager::getRecord(const String& name) const
{
	if (!mRecordMap.count(name))
	{
		printDebug(U"[RecordManager::setRecord]");
		printDebug(U"�o�^����Ă��Ȃ����R�[�h�ł�");
		printDebug(U"name > " + name);
		return 0;
	}

	return mRecordMap.find(name)->second.get();
}


String Kokoha::RecordManager::encryption() const
{
	// �Í��p�̃��X�g
	std::list<int32> dataList;

	// �e���R�[�h���� 0 1 �̃��X�g��ǉ�
	for (const auto& record : mRecordMap)
	{
		record.second.addRecordToEncryptionList(dataList);
	}

	// 0 -> [0x2,0x10]�͈̔͂̋���
	// 1 -> [0x1,0xF] �͈̔͂̊
	for (auto& data : dataList)
	{
		data = 2 * (Random(0x1, HALF)) - data;
	}
	
	// �S�Ă�0xF������
	for (auto& data : dataList)
	{
		data *= MUL;
	}

	// ���𐶐����� 
	int32 key = Random(0x0, MAX_KEY);

	// ���X�g�̐擪�Ɩ����Ɍ���ǉ�
	dataList.emplace_front(key);
	dataList.emplace_back(key);

	// �O�̍��̒l�� mod 0x100 �ŉ��Z
	int32 previousOne = 0;
	for (auto& data : dataList)
	{
		data = (data + previousOne) % MOD;
		previousOne = data;
	}
	
	// �����l�̔z�� -> ������
	String rtn;
	for (const auto& data : dataList)
	{
		rtn += Pad(U"{:x}"_fmt(data), { ONE_DATA_LENGTH, U'0' });
	}

	return std::move(rtn);
}


bool Kokoha::RecordManager::decryption(const String& str)
{
	// �����p�̃��X�g
	std::list<int32> dataList;

	// ������ -> �����l�̔z��
	for (size_t i = 0; i < str.length(); i += ONE_DATA_LENGTH)
	{
		auto data = ParseIntOpt<int32>(str.substr(i, ONE_DATA_LENGTH), Arg::radix = BASE);
		if (!data)
		{
			return false; // �ϊ��ł��Ȃ��Ƃ����s
		}
		dataList.emplace_back(*data);
	}
	
	// �O�̍��̒l�� mod 0x100 �� ���Z
	int32 previouseOne = 0;
	for (auto& data : dataList)
	{
		int32 temp = data;
		data = (data - previouseOne + MOD) % MOD;
		previouseOne = temp;
	}

	// �擪�E�����̌����폜
	if (*dataList.begin() != *dataList.rbegin())
	{
		return false; // ������v���Ȃ��Ƃ����s
	}
	dataList.pop_front();
	dataList.pop_back();
	
	// �T�C�Y �� ���R�[�h�̍��v���� ����v���Ă��邩�m�F
	if (dataList.size() != Record::getDigitTotal())
	{
		return false; // ��v���Ȃ��Ƃ����s
	}
	
	// �S�Ă�0xF�Ŋ���
	for (auto& data : dataList)
	{
		if (data % MUL != 0)
		{
			return false; // ����؂�Ȃ��Ƃ����s
		}
		data /= MUL;
		if (data <= 0x0 || data > BASE)
		{
			return false; // [0x1,0x10]�͈̔͂ɂȂ��Ƃ����s
		}
	}
	
	// ���� -> 0
	// � -> 1
	for (auto& data : dataList)
	{
		data %= 2;
	}

	// ���R�[�h�Ɋi�[
	for (auto& record : mRecordMap)
	{
		record.second.setValueFromDecryption(dataList);
	}

	return true;
}
