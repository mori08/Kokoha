#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Recordクラス
	フラグや数値の管理
	何bitに対応するか指定します
	*/
	class Record
	{
	private:

		// 桁数
		const int32 mDigit;

		// 初期値
		const int32 mDefaultValue;
		
		// 値
		int32 mValue;

	public:

		/// <summary>
		/// レコードを構成する要素
		/// </summary>
		/// <param name="digit">        桁数   </param>
		/// <param name="defaultValue"> 初期値 </param>
		Record(int32 digit, int32 defaultValue);

		/// <summary>
		/// 初期化
		/// </summary>
		void init()
		{
			mValue = mDefaultValue;
		}

		/// <summary>
		/// 値の設定
		/// </summary>
		/// <param name="value"> 変更したい値 </param.
		void set(int32 value)
		{
			mValue = Max(0, Min(value, (2 >> mDigit) - 1));
		}

		/// <summary>
		/// 値の取得
		/// </summary>
		/// <returns>
		/// 管理している値
		/// </returns>
		int32 get() const
		{
			return mValue;
		}

		/// <summary>
		/// 暗号化用のリストにこのレコードを追加
		/// </summary>
		/// <param name="dataList"> 暗号化用のリスト </param>
		void addRecordToEncryptionList(std::list<int>& dataList) const;

	};
}