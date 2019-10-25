#include "GameManager.h"
#include "../MyColor.h"


void Kokoha::GameManager::init()
{
	mStageData.init();
}


Optional<String> Kokoha::GameManager::load(const String& fileName)
{
	// ������
	init();

	// �G���[���b�Z�[�W
	String errorMessage = U"[AdventureManager::load]\n";

	// CSV�t�@�C���̊m�F
	CSVData csv(fileName);
	if (csv.isEmpty())
	{
		errorMessage += U"CSV�t�@�C����ǂݍ��߂܂���.\n";
		errorMessage += U"�t�@�C���� > " + fileName;
		return errorMessage;
	}
	
	int32 readingRow = 0;

	// �X�e�[�W�̐ݒ�
	if (csv.rows() < StageData::HEIGHT)
	{
		errorMessage += U"csv�f�[�^�̍s��������܂���";
		errorMessage += U"�s�� > + " + ToString(1 + csv.rows());
		return errorMessage;
	}
	for (readingRow = 0; readingRow < StageData::HEIGHT; ++readingRow)
	{
		if (csv.columns(readingRow) < StageData::WIDTH)
		{
			errorMessage += U"csv�f�[�^�̗񐔂�����܂���";
			errorMessage += ToString(readingRow + 1) + U"�s�ڂ̗� > + " + ToString(csv.rows());
			return errorMessage;
		}
		for (int32 column = 0; column < StageData::WIDTH; ++column)
		{
			if (csv[readingRow][column] == U"1")
			{
				mStageData.setWall(Point(column, readingRow));
			}
		}
	}

	// �o�H�T��
	mStageData.searchPath();
	
	return none;
}


void Kokoha::GameManager::update()
{

}


void Kokoha::GameManager::draw() const
{
	Scene::Rect().draw(MyWhite);
	mStageData.draw();
}
