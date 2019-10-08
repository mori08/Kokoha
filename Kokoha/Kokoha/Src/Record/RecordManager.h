#pragma once


#include "Record.h"


namespace Kokoha
{
	/*
	RecordManagerクラス
	レコード (セーブデータ) のロードやセーブ,
	フラグや数値の変更,取得を行えます.
	*/
	class RecordManager
	{
	public:

		enum class LoadResult
		{
			NEW_GAME, // RECORD.txtが存在しないとき
			CONTINUE, // RECORD.txtを正しく読み込めたとき
			ERROR     // RECORD.txtを正しく読み込めないとき
		};

	private:

		// レコードのマップ
		std::map<String, Record> mRecordMap;

	private:

		RecordManager();

		RecordManager(const RecordManager&)            = default;
		RecordManager& operator=(const RecordManager&) = default;
		RecordManager(RecordManager&&)                 = default;
		RecordManager& operator=(RecordManager&&)      = default;

	public:

		/// <summary>
		/// シングルトンとして管理しているRecordManagerのインスタンスの取得
		/// </summary>
		/// <returns>
		/// インスタンス
		/// </summary>
		static RecordManager& instatnce()
		{
			static RecordManager recordManager;
			return recordManager;
		}

		/// <summary>
		/// RECORD.txtからロード
		/// </summary>
		LoadResult load();

		/// <summary>
		/// 全レコードの初期化
		/// </summary>
		void initAllRecord();

		/// <summary>
		/// RECORD.txtにセーブ
		/// </summary>
		void save();

	private:

		/// <summary>
		/// レコードの暗号化
		/// </summary>
		/// <returns>
		/// 暗号化した後の文字列
		/// </returns>
		String encryption() const;

	};
}