#include "RecordManager.h"


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
	mRecordMap.try_emplace(U"TestFlag" , std::move(Record(1, 0)));
	mRecordMap.try_emplace(U"TestValue", std::move(Record(3, 5)));
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

	if (reader.readLine(line))
	{
		// ����
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


String Kokoha::RecordManager::encryption() const
{
	// �Í����p�̃��X�g
	std::list<int> dataList;

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
	
	// 0xF��S�Ăɂ�����
	for (auto& data : dataList)
	{
		data *= MUL;
	}

	// ���𐶐����� (����0x0�ɂ͂��Ȃ�)
	int32 key = Random(0x1, MAX_KEY);

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
	
	// ������֕ϊ�
	String rtn;
	for (const auto& data : dataList)
	{
		rtn += Pad(U"{:x}"_fmt(data), { ONE_DATA_LENGTH, U'0' });
	}

	return std::move(rtn);
}
