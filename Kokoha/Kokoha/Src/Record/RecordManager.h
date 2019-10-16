#pragma once


#include "Record.h"


namespace Kokoha
{
	/*
	RecordManager�N���X
	���R�[�h (�Z�[�u�f�[�^) �̃��[�h��Z�[�u,
	�t���O�␔�l�̕ύX,�擾���s���܂�.
	*/
	class RecordManager
	{
	public:

		enum class LoadResult
		{
			NEW_GAME, // RECORD.txt�����݂��Ȃ��Ƃ�
			CONTINUE, // RECORD.txt�𐳂����ǂݍ��߂��Ƃ�
			ERROR     // RECORD.txt�𐳂����ǂݍ��߂Ȃ��Ƃ�
		};

	private:

		// ���R�[�h�̃}�b�v
		std::map<String, Record> mRecordMap;

	private:

		RecordManager();

		RecordManager(const RecordManager&)            = default;
		RecordManager& operator=(const RecordManager&) = default;
		RecordManager(RecordManager&&)                 = default;
		RecordManager& operator=(RecordManager&&)      = default;

	public:

		/// <summary>
		/// �V���O���g���Ƃ��ĊǗ����Ă���RecordManager�̃C���X�^���X�̎擾
		/// </summary>
		/// <returns>
		/// �C���X�^���X
		/// </summary>
		static RecordManager& instatnce()
		{
			static RecordManager recordManager;
			return recordManager;
		}

		/// <summary>
		/// RECORD.txt���烍�[�h
		/// </summary>
		LoadResult load();

		/// <summary>
		/// �S���R�[�h�̏�����
		/// </summary>
		void initAllRecord();

		/// <summary>
		/// RECORD.txt�ɃZ�[�u
		/// </summary>
		void save();

		/// <summary>
		/// �Ǘ����Ă��郌�R�[�h�̓��e�̕\��
		/// </summary>
		/// <remarks>
		/// �f�o�b�O�p
		/// </remarks>
		void printAllRecord();

	private:

		/// <summary>
		/// ���R�[�h�̈Í���
		/// </summary>
		/// <returns>
		/// �Í���������̕�����
		/// </returns>
		String encryption() const;

		/// <summary>
		/// �Í����𕜍�, �t���O�̃��X�g�Ɋi�[
		/// </summary>
		/// <param name="str"> �Í��� </param>
		/// <returns> �����ɐ��������Ƃ� true , �����łȂ��Ƃ� false </returns>
		bool decryption(const String& str);

	};
}