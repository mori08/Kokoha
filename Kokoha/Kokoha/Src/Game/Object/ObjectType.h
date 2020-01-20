#pragma once


#include<Siv3D.hpp>


namespace Kokoha
{
	/*
	ObjectType�N���X
	GameObject�̎��(�̏W��)
	int32�^��1bit��1��ނɊ��蓖�Ă�
	|���Z�q�ŕ����̎�ނ̘a�W�����������Ƃ��ł���
	*/
	class ObjectType
	{
	private:

		uint8 mValue;

	public:

		static const ObjectType PLAYER;      // �v���C���[

		static const ObjectType BLACK_ENEMY; // �����G

		static const ObjectType WHITE_ENEMY; // �����G

		static const ObjectType ENEMY;       // �G

		static const ObjectType LIGHT;       // ��

		static const ObjectType ATTACK;      // �U��

		static const ObjectType GOAL;        // �S�[��

	private:

		/// <summary>
		/// �I�u�W�F�N�g�̎��
		/// </summary>
		constexpr ObjectType(uint8 value)
			: mValue(value)
		{
		}

	public:

		/// <summary>
		/// �a�W���̍쐬
		/// </summary>
		ObjectType operator|(const ObjectType& another)const
		{
			return ObjectType(mValue | another.mValue);
		}

		/// <summary>
		/// �ϏW���̍쐬
		/// </summary>
		ObjectType operator&(const ObjectType& another)const
		{
			return ObjectType(mValue & another.mValue);
		}

		/// <summary>
		/// ���W���̍쐬
		/// </summary>
		ObjectType operator-(const ObjectType& another)const
		{
			return ObjectType(mValue & ~another.mValue);
		}

		/// <summary>
		/// �W���ɒǉ�
		/// </summary>
		const ObjectType& operator|=(const ObjectType& another)
		{
			mValue |= another.mValue;
			return *this;
		}

		/// <summary>
		/// �W������폜
		/// </summary>
		const ObjectType& operator-=(const ObjectType& another)
		{
			mValue &= ~another.mValue;
			return *this;
		}

		/// <summary>
		/// ��W���̎擾
		/// </summary>
		const ObjectType operator~()const
		{
			return ObjectType(~mValue);
		}

		/// <summary>
		/// ��W���̂Ƃ� false , �����łȂ��Ƃ� true
		/// </summary>
		explicit operator bool() const
		{
			return mValue != 0;
		}

	};
}