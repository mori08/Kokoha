#include "RecordManager.h"
#include "../MyLibrary.h"
#include "../Cassette/CassetteManager.h"


namespace
{
	// レコードを保存するファイル名
	const String RECORD_TEXT_NAME = U"SAVE_DATA.txt";

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
	mRecordMap.try_emplace(U"TestFlag" , std::move(Record(1, 1)));
	mRecordMap.try_emplace(U"TestValue", std::move(Record(3, 5)));

	// Adventureでのプレイヤーの位置
	mRecordMap.try_emplace(U"AreaId"         , std::move(Record(3, 0)));
	mRecordMap.try_emplace(U"PlayerPos"      , std::move(Record(11, 382)));
	mRecordMap.try_emplace(U"PlayerDirection", std::move(Record(1, 1)));

	// ステージのクリア状況
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

	// カセット
	mRecordMap.try_emplace(U"CassetteCount", std::move(Record(3, 1)));
	for (const auto& cassette : CassetteManager::instance().getCassetteList())
	{
		if (cassette->NAME == U"スピードI" || cassette->NAME == U"プレイヤーI")
		{
			/*
				初期装備カセットは初期化値が違うためここではスキップ
				個別にレコードに登録する
			*/
			continue;
		}

		mRecordMap.try_emplace(cassette->NAME, std::move(Record(2, Cassette::NO_POSSESS_STATE)));
	}
	mRecordMap.try_emplace(U"スピードI"  , std::move(Record(2, Cassette::EQUIPMENT_A_STATE)));
	mRecordMap.try_emplace(U"プレイヤーI", std::move(Record(2, Cassette::EQUIPMENT_B_STATE)));
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
#ifdef _DEBUG

	ClearPrint();
	int32 cnt = 0;
	String text;
	for (auto& record : mRecordMap)
	{
		text += U"[" + record.first + U" : " + ToString(record.second.get()) + U"]";
		
		if (++cnt % 3 == 0) { Print << text; text = U""; }
	}

#endif // _DEBUG
}


void Kokoha::RecordManager::setRecord(const String& name, int32 value)
{
	if (!mRecordMap.count(name)) 
	{ 
		printDebug(U"[RecordManager::setRecord]");
		printDebug(U"登録されていないレコードです");
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
		printDebug(U"登録されていないレコードです");
		printDebug(U"name > " + name);
		return 0;
	}

	return mRecordMap.find(name)->second.get();
}


String Kokoha::RecordManager::encryption() const
{
	// 暗号用のリスト
	std::list<int32> dataList;

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
	
	// 全てを0xFかける
	for (auto& data : dataList)
	{
		data *= MUL;
	}

	// 鍵を生成する 
	int32 key = Random(0x0, MAX_KEY);

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
	
	// 整数値の配列 -> 文字列
	String rtn;
	for (const auto& data : dataList)
	{
		rtn += Pad(U"{:x}"_fmt(data), { ONE_DATA_LENGTH, U'0' });
	}

	return std::move(rtn);
}


bool Kokoha::RecordManager::decryption(const String& str)
{
	// 復号用のリスト
	std::list<int32> dataList;

	// 文字列 -> 整数値の配列
	for (size_t i = 0; i < str.length(); i += ONE_DATA_LENGTH)
	{
		auto data = ParseIntOpt<int32>(str.substr(i, ONE_DATA_LENGTH), Arg::radix = BASE);
		if (!data)
		{
			return false; // 変換できないとき失敗
		}
		dataList.emplace_back(*data);
	}
	
	// 前の項の値と mod 0x100 で 減算
	int32 previouseOne = 0;
	for (auto& data : dataList)
	{
		int32 temp = data;
		data = (data - previouseOne + MOD) % MOD;
		previouseOne = temp;
	}

	// 先頭・末尾の鍵を削除
	if (*dataList.begin() != *dataList.rbegin())
	{
		return false; // 鍵が一致しないとき失敗
	}
	dataList.pop_front();
	dataList.pop_back();
	
	// サイズ と レコードの合計桁数 が一致しているか確認
	if (dataList.size() != Record::getDigitTotal())
	{
		return false; // 一致しないとき失敗
	}
	
	// 全てを0xFで割る
	for (auto& data : dataList)
	{
		if (data % MUL != 0)
		{
			return false; // 割り切れないとき失敗
		}
		data /= MUL;
		if (data <= 0x0 || data > BASE)
		{
			return false; // [0x1,0x10]の範囲にないとき失敗
		}
	}
	
	// 偶数 -> 0
	// 奇数 -> 1
	for (auto& data : dataList)
	{
		data %= 2;
	}

	// レコードに格納
	for (auto& record : mRecordMap)
	{
		record.second.setValueFromDecryption(dataList);
	}

	return true;
}
