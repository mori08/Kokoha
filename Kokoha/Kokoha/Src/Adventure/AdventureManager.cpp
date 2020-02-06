#include "AdventureManager.h"
#include "../MyColor.h"
#include "../Input/InputManager.h"
#include "Window/MenuWindow.h"
#include "../Record/RecordManager.h"


namespace
{
	// �����̕��̍s��
	constexpr size_t ROOM_WIDTH_ROW = 0;

	// �v���C���[�ɂ��Ă̍s��
	constexpr size_t PLAYER_ROW = 1;
	// �v���C���[�̍��W�ɂ��Ă̗�
	constexpr size_t PLAYER_POS_COLUMN = 0;
	// �v���C���[�̕����ɂ��Ă̗�
	constexpr size_t PLAYER_DIRECTION_COLUMN = 1;

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

	// �`��͈�
	constexpr Rect SIZE(0, 0, 640, 420);

	// �X�e�[�W�t�@�C����
	const Array<String> AREA_FILE_NAME
	{
		U"StoreRoom",
		U"StoreRoom",
		U"StoreRoom",
		U"DoctorRoom",
		U"StoreRoom",
		U"StoreRoom",
		U"StoreRoom"
	};
}


Kokoha::AdventureManager::AdventureManager()
	: mCameraPos(0,0)
	, mAreaId(0)
{
	AdventureObject::registerWindow();
}


Optional<String> Kokoha::AdventureManager::load()
{
	// �V�[���J�ڐ�̏�����
	mSceneName = none;

	// �G���[���b�Z�[�W
	String errorMessage = U"[AdventureManager::load]\n";

	// �t�B�[���h���̏�����
	mObjectList.clear();

	// �X�e�[�W�ԍ����t�@�C�����ɕϊ�
	String fileName = AREA_FILE_NAME[Max(0, Min(mAreaId, (int32)AREA_FILE_NAME.size() - 1))];
	fileName = U"Assets/Data/Adventure/" + fileName + U".csv";
	RecordManager::instance().setRecord(U"AreaId", mAreaId);

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
		errorMessage += U"�����̕� > " + csv[ROOM_WIDTH_ROW][0] + U"\n";
		errorMessage += fileName + U" : " + ToString(ROOM_WIDTH_ROW + 1) + U"�s��";
		return errorMessage;
	}

	// �v���C���[�̏����ʒu
	try
	{
		mPlayer.set
		(
			Parse<int32>(csv[PLAYER_ROW][PLAYER_POS_COLUMN]),
			Parse<int32>(csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN])
		);
		changeCameraPos();
	}
	catch (const ParseError&)
	{
		errorMessage += U"�����l�ɕϊ��ł��܂���.\n";
		errorMessage += U"���W > " + csv[PLAYER_ROW][PLAYER_POS_COLUMN] + U"\n";
		errorMessage += U"���� > " + csv[PLAYER_ROW][PLAYER_DIRECTION_COLUMN] + U"\n";
		errorMessage += fileName + U" : " + ToString(PLAYER_ROW + 1) + U"�s��";
		return errorMessage;
	}

	// ���E�ɕǂƂȂ�I�u�W�F�N�g�̐ݒu
	mObjectList.emplace_back
	(
		Point(-10, 0),
		U"Invisible",
		false
	);
	mObjectList.emplace_back
	(
		Point(mRoomWidth, 0),
		U"Invisible",
		false
	);

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
		catch(const ParseError&)
		{
			errorMessage += U"�I�u�W�F�N�g�𐶐��ł��܂���.\n";
			errorMessage += fileName + U" : " + ToString(row + 1) + U"�s��";
			return errorMessage;
		}
	}

	// �E�B���h�E��S�ĕ���
	mWindowList.clear();

	return none;
}


void Kokoha::AdventureManager::setPlayerFromRecord()
{
	mPlayer.set
	(
		RecordManager::instance().getRecord(U"PlayerPos"),
		(RecordManager::instance().getRecord(U"PlayerDirection") == 1) ? (+1) : (-1)
	);

	changeCameraPos();
}


void Kokoha::AdventureManager::update()
{
	// �E�B���h�E���J���Ă���Ƃ� ���̍X�V
	if (!mWindowList.empty())
	{
		for (auto&& window : mWindowList) { window->update(); }
		mWindowList.back()->selectedUpdate();
		return;
	}

	// �L�����Z���{�^���Ń��j���[���J��
	if (InputManager::instance().cancel())
	{
		openWindow(std::make_unique<MenuWindow>());
		return;
	}

	// �I�u�W�F�N�g�̍X�V
	mPlayer.update(mObjectList);
	changeCameraPos();
	for (auto& object : mObjectList)
	{
		object.update(mPlayer.getRegion());
	}
}


void Kokoha::AdventureManager::draw() const
{
	SIZE.draw(MyWhite);

	mPlayer.draw(mCameraPos);

	for (const auto& object : mObjectList)
	{
		object.draw(mCameraPos);
	}

	for (const auto& window : mWindowList)
	{
		window->draw();
	}
}


void Kokoha::AdventureManager::closeWindow()
{
	if (mWindowList.empty()) { return; }
	mWindowList.pop_back();
	
	if (!mWindowList.empty())
	{
		mWindowList.back()->select();
	}
}


void Kokoha::AdventureManager::clearWindow()
{
	mWindowList.clear();
}


void Kokoha::AdventureManager::changeCameraPos()
{
	int32 x = mPlayer.getRegion().center().asPoint().x - Scene::Center().x;

	if (mRoomWidth < Scene::Width())
	{
		mCameraPos.x = x;
		return;
	}

	mCameraPos.x = Max(0, Min(x, mRoomWidth - Scene::Width()));
}
