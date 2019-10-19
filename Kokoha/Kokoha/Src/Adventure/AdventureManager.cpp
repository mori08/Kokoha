#include "AdventureManager.h"


namespace
{
	// �����̕��̍s��
	constexpr size_t ROOM_WIDTH_ROW = 0;
	// �v���C���[�̍��W�̍s��
	constexpr size_t PLAYER_POS_ROW = 1;
	// �I�u�W�F�N�g�̏��̍s��
	constexpr size_t OBJECT_ROW = 2;
	// �I�u�W�F�N�g�̍��W�̗�
	constexpr size_t POS_COLUMN = 0;
	
	// �I�u�W�F�N�g�̉摜���̗�
	constexpr size_t TEXTURE_NAME_COLUMN = 1;
	// �I�u�W�F�N�g�̒ʉ߉\�t���O�̗�
	constexpr size_t IS_PASSING_COLUMN = 2;
	// �J���E�B���h�E���̗�
	constexpr size_t WINDOW_NAME_COLUMN = 3;

	// ���������`��͈͂̃T�C�Y
	constexpr Size ADVENTURE_SIZE(640, 420);
}


Kokoha::AdventureManager::AdventureManager()
{
	
}


Optional<String> Kokoha::AdventureManager::load(const String& fileName)
{
	// �G���[���b�Z�[�W
	String errorMessage = U"[AdventureManager::load]\n";

	// �t�B�[���h���̏�����
	mObjectList.clear();

	// CSV�t�@�C���̊m�F
	CSVData csv(fileName);
	if (csv.isEmpty())
	{
		errorMessage += U"CSV�t�@�C����ǂݍ��߂܂���.\n";
		errorMessage += U"�t�@�C���� > " + fileName;
		return errorMessage;
	}

	// �����̕��͈̔�
	try
	{
		mRoomWidth = Parse<int32>(csv[ROOM_WIDTH_ROW][0]);
	}
	catch (const ParseError&)
	{
		errorMessage += U"�����l�ɕϊ��ł��܂���.\n";
		errorMessage += fileName + U" : " + ToString(ROOM_WIDTH_ROW + 1) + U"�s��";
		return errorMessage;
	}

	// �v���C���[�͈̔�
	try
	{
		mPlayerRegion.setPos(Parse<int32>(csv[PLAYER_POS_ROW][0]), ADVENTURE_SIZE.y - PLAYER_SIZE.y);
	}
	catch (const ParseError&)
	{
		errorMessage += U"�����l�ɕϊ��ł��܂���.\n";
		errorMessage += fileName + U" : " + ToString(PLAYER_POS_ROW + 1) + U"�s��";
		return errorMessage;
	}

	// �I�u�W�F�N�g�̐���
	for (size_t row = OBJECT_ROW; row < csv.rows(); ++row)
	{
		try
		{
			mObjectList.emplace_back
			(
				Parse<Point>(csv[row][POS_COLUMN]),
				csv[row][TEXTURE_NAME_COLUMN],
				Parse<bool>(csv[row][IS_PASSING_COLUMN])
			);
		}
		catch(const ParseError& e)
		{
			errorMessage += U"�I�u�W�F�N�g�𐶐��ł��܂���.\n";
			errorMessage += fileName + U" : " + ToString(row + 1) + U"�s��";
			return errorMessage;
		}
	}

	return none;
}


void Kokoha::AdventureManager::update()
{
	for (auto& object : mObjectList)
	{
		object.update(mPlayerRegion);
	}
}


void Kokoha::AdventureManager::draw() const
{
	for (const auto& object : mObjectList)
	{
		object.draw(mCameraPos);
	}
}
