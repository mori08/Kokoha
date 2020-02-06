#include "GameManager.h"
#include "../MyColor.h"

// �I�u�W�F�N�g
#include "Object/Player/GamePlayer.h"
#include "Object/Enemy/ChaseEnemy.h"
#include "Object/Light/EnemyLight.h"
#include "Object/Attack/ChaseEnemyAttack.h"
#include "Object/Goal/GameGoal.h"
#include "Object/Goal/RandomGoal.h"
#include "Object/Goal/RunAwayGoal.h"

// ���
#include "State/PlayingState.h"
#include "State/InfoState.h"

#include "../Cassette/CassetteManager.h"
#include "../Input/InputManager.h"


namespace
{
	// �I�u�W�F�N�g�̖��O�̗�
	constexpr size_t OBJECT_NAME_COLUMN = 0;
	// �I�u�W�F�N�g�̍��W�̗�
	constexpr size_t OBJECT_POS_COLUMN = 1;
}


Kokoha::GameManager::GameManager()
	: mState(std::make_unique<PlayingState>())
{
	// �v���C���[
	setGenerateObjectFunc<GamePlayer>(U"Player");

	// �G
	setGenerateObjectFunc<BlackEnemy>            (U"BlackStop");
	setGenerateObjectFunc<ChaseEnemy<BlackEnemy>>(U"BlackChase");
	setGenerateObjectFunc<ChaseEnemy<WhiteEnemy>>(U"WhiteChase");

	// �S�[��
	setGenerateObjectFunc<GameGoal>   (U"Goal");
	setGenerateObjectFunc<RandomGoal> (U"RandomGoal");
	setGenerateObjectFunc<RunAwayGoal>(U"RunAwayGoal");

	InfoState::setInfoMap();
}


void Kokoha::GameManager::init()
{
	// ��Ԃ̏�����
	setState(std::make_unique<PlayingState>());

	// �X�e�[�W�̏�����
	mStageData.init();

	// �I�u�W�F�N�g�̑S�폜
	mObjectList.clear();

	// �����̏�����
	mEquipmentId = 0;
	CassetteManager::instance().getEquipment(mEquipmentId).initEffect();

	// �v���C���[�̑����̏�����
	mPlayerSpeed.init();
}


Optional<String> Kokoha::GameManager::load()
{
	const FilePath filePath = U"Assets/Data/Game/" + mName + U".csv";

	// ������
	init();

	// �G���[���b�Z�[�W
	String errorMessage = U"[AdventureManager::load]\n";

	// CSV�t�@�C���̊m�F
	CSVData csv(filePath);
	if (!csv)
	{
		errorMessage += U"CSV�t�@�C����ǂݍ��߂܂���.\n";
		errorMessage += U"�t�@�C���� > " + filePath;
		return errorMessage;
	}
	
	errorMessage += U"�t�@�C���� > " + filePath;
	int32 readingRow = 0;

	// �X�e�[�W�̐ݒ�
	if (csv.rows() < StageData::HEIGHT)
	{
		errorMessage += U"csv�f�[�^�̍s��������܂���\n";
		errorMessage += U"�s�� > + " + ToString(1 + csv.rows());
		return errorMessage;
	}
	for (readingRow = 0; readingRow < StageData::HEIGHT; ++readingRow)
	{
		if (csv.columns(readingRow) < StageData::WIDTH)
		{
			errorMessage += U"csv�f�[�^�̗񐔂�����܂���\n";
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

	// �I�u�W�F�N�g�̐���
	for (; readingRow < csv.rows(); ++readingRow)
	{
		const String& OBJ_NAME = csv[readingRow][OBJECT_NAME_COLUMN];
		if (!mGenerateObjectMap.count(OBJ_NAME))
		{
			errorMessage += ToString(readingRow + 1) + U"�s��.\n";
			errorMessage += U"�o�^����Ă��Ȃ��I�u�W�F�N�g�ł�.\n";
			errorMessage += U"���o�l > " + OBJ_NAME;
			return errorMessage;
		}

		try
		{
			Vec2 pos = StageData::squareToPixel(Parse<Point>(csv[readingRow][OBJECT_POS_COLUMN]));
			mObjectList.emplace_back(mGenerateObjectMap[OBJ_NAME](pos));
		}
		catch (const ParseError&)
		{
			errorMessage += ToString(readingRow + 1) + U"�s��.\n";
			errorMessage += U"���W�ɕϊ��ł��܂���.\n";
			errorMessage += U"���o�l > " + csv[readingRow][OBJECT_POS_COLUMN];
			return errorMessage;
		}
	}
	
	return none;
}


void Kokoha::GameManager::update()
{
	// �����̐؂�ւ�
	if (InputManager::instance().decision())
	{
		changeEquipment();
	}
	// �����̍X�V
	CassetteManager::instance().getEquipment(mEquipmentId).updateEffect();

	// �v���C���[�̑��x�̍X�V
	mPlayerSpeed.update();

	// �I�u�W�F�N�g�̒ǉ�
	for (auto&& object : mAddObjectList) { mObjectList.emplace_back(std::move(object)); }
	mAddObjectList.clear();

	// �I�u�W�F�N�g�̍X�V
	GameEnemy::lightUpdate();
	for (auto&& object : mObjectList) { object->update(); }

	// ���I�u�W�F�N�g�̊m�F
	for (auto&& objA = mObjectList.begin(); objA != mObjectList.end(); ++objA)
	{
		auto objB = objA;
		while (++objB != mObjectList.end())
		{
			(*objA)->checkAnother(**objB);
			(*objB)->checkAnother(**objA);
		}
	}

	// �I�u�W�F�N�g�̍폜
	Erase_if(mObjectList, [](const GameObjectPtr& obj) {return obj->isEraseAble(); });
}


void Kokoha::GameManager::draw() const
{
#ifdef _DEBUG
	static bool debugMode = false;
	debugMode ^= Key0.up();

	// �f�o�b�O���ɔ�������ƃ}�X����������`��
	if (debugMode)
	{
		Scene::Rect().draw(Color(MyWhite, 0x40));
		for (int32 i = 0; i < StageData::N; ++i)
		{
			const Point square = StageData::integerToSquare(i);
			Rect(StageData::SQUARE_SIZE * square, StageData::SQUARE_SIZE).drawFrame(1, MyBlack);
		}
	}
#endif // _DEBUG

	for (const auto& object : mObjectList) { object->drawLight(); }

	for (const auto& object : mObjectList) { object->draw(); }

	mStageData.draw();
}


void Kokoha::GameManager::changeEquipment()
{
	++mEquipmentId;

	mPlayerSpeed.init();

	GameEnemy::lightOff();

	CassetteManager::instance().getEquipment(mEquipmentId).initEffect();
}
