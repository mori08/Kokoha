#pragma once


#include<Siv3D.hpp>


namespace Kokoha
{
	/*
	ObjectTypeクラス
	GameObjectの種類(の集合)
	int32型の1bitを1種類に割り当てる
	|演算子で複数の種類の和集合を示すことができる
	*/
	class ObjectType
	{
	private:

		uint8 mValue;

	public:

		static const ObjectType PLAYER;      // プレイヤー

		static const ObjectType BLACK_ENEMY; // 黒い敵

		static const ObjectType WHITE_ENEMY; // 白い敵

		static const ObjectType ENEMY;       // 敵

		static const ObjectType LIGHT;       // 光

		static const ObjectType ATTACK;      // 攻撃

		static const ObjectType GOAL;        // ゴール

	private:

		/// <summary>
		/// オブジェクトの種類
		/// </summary>
		constexpr ObjectType(uint8 value)
			: mValue(value)
		{
		}

	public:

		/// <summary>
		/// 和集合の作成
		/// </summary>
		ObjectType operator|(const ObjectType& another)const
		{
			return ObjectType(mValue | another.mValue);
		}

		/// <summary>
		/// 積集合の作成
		/// </summary>
		ObjectType operator&(const ObjectType& another)const
		{
			return ObjectType(mValue & another.mValue);
		}

		/// <summary>
		/// 差集合の作成
		/// </summary>
		ObjectType operator-(const ObjectType& another)const
		{
			return ObjectType(mValue & ~another.mValue);
		}

		/// <summary>
		/// 集合に追加
		/// </summary>
		const ObjectType& operator|=(const ObjectType& another)
		{
			mValue |= another.mValue;
			return *this;
		}

		/// <summary>
		/// 集合から削除
		/// </summary>
		const ObjectType& operator-=(const ObjectType& another)
		{
			mValue &= ~another.mValue;
			return *this;
		}

		/// <summary>
		/// 補集合の取得
		/// </summary>
		const ObjectType operator~()const
		{
			return ObjectType(~mValue);
		}

		/// <summary>
		/// 空集合のとき false , そうでないとき true
		/// </summary>
		explicit operator bool() const
		{
			return mValue != 0;
		}

	};
}