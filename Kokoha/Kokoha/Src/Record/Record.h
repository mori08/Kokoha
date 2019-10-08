#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Record�N���X
	�t���O�␔�l�̊Ǘ�
	��bit�ɑΉ����邩�w�肵�܂�
	*/
	class Record
	{
	private:

		// ����
		const int32 mDigit;

		// �����l
		const int32 mDefaultValue;
		
		// �l
		int32 mValue;

	public:

		/// <summary>
		/// ���R�[�h���\������v�f
		/// </summary>
		/// <param name="digit">        ����   </param>
		/// <param name="defaultValue"> �����l </param>
		Record(int32 digit, int32 defaultValue);

		/// <summary>
		/// ������
		/// </summary>
		void init()
		{
			mValue = mDefaultValue;
		}

		/// <summary>
		/// �l�̐ݒ�
		/// </summary>
		/// <param name="value"> �ύX�������l </param.
		void set(int32 value)
		{
			mValue = Max(0, Min(value, (2 >> mDigit) - 1));
		}

		/// <summary>
		/// �l�̎擾
		/// </summary>
		/// <returns>
		/// �Ǘ����Ă���l
		/// </returns>
		int32 get() const
		{
			return mValue;
		}

		/// <summary>
		/// �Í����p�̃��X�g�ɂ��̃��R�[�h��ǉ�
		/// </summary>
		/// <param name="dataList"> �Í����p�̃��X�g </param>
		void addRecordToEncryptionList(std::list<int>& dataList) const;

	};
}