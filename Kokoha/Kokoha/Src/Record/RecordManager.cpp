#include "RecordManager.h"


namespace
{
	// レコードを保存するファイル名
	const String RECORD_TEXT_NAME = U"Assets/Data/RECORD.txt";

	constexpr int32 BASE    = 0x10;      // 暗号化の基準になる値(何進数で暗号化するか)
	constexpr int32 MUL     = BASE - 1;  // 掛け算のときのかける数
	constexpr int32 HALF    = BASE / 2;  // 基準値の半分
	constexpr int32 MOD     = BASE*BASE; // 余りをとるときの割る数 
	constexpr int32 MAX_KEY = MOD - 1;   // 鍵の最大値

	// 暗号文における1データのとる文字数
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

	// RECORD.txtが存在しないとき NEWGAME
	if (!reader.isOpened())
	{
		initAllRecord();
		return LoadResult::NEW_GAME;
	}

	String line;

	if (reader.readLine(line))
	{
		// 復号
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
	// 暗号化用のリスト
	std::list<int> dataList;

	// 各レコードから 0 1 のリストを追加
	for (const auto& record : mRecordMap)
	{
		record.second.addRecordToEncryptionList(dataList);
	}

	// 0 -> [0x2,0x10]の範囲の偶数
	// 1 -> [0x1,0xF] の範囲の奇数
	for (auto& data : dataList)
	{
		data = 2 * (Random(0x1, HALF)) - data;
	}
	
	// 0xFを全てにかける
	for (auto& data : dataList)
	{
		data *= MUL;
	}

	// 鍵を生成する (鍵は0x0にはしない)
	int32 key = Random(0x1, MAX_KEY);

	// リストの先頭と末尾に鍵を追加
	dataList.emplace_front(key);
	dataList.emplace_back(key);

	// 前の項の値を mod 0x100 で加算
	int32 previousOne = 0;
	for (auto& data : dataList)
	{
		data = (data + previousOne) % MOD;
		previousOne = data;
	}
	
	// 文字列へ変換
	String rtn;
	for (const auto& data : dataList)
	{
		rtn += Pad(U"{:x}"_fmt(data), { ONE_DATA_LENGTH, U'0' });
	}

	return std::move(rtn);
}
