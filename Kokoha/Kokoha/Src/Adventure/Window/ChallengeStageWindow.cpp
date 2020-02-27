#include "ChallengeStageWindow.h"
#include "SetupWindow.h"
#include "../AdventureManager.h"
#include "../../Input/ButtonManager.h"
#include "../../Game/GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"


namespace
{
	// �E�B���h�E�̃T�C�Y
	constexpr Size WINDOW_SIZE(360, 180);

	// �e�L�X�g��\��������W
	constexpr Point TEXT_POS(320, 180);

	// �u�A�N�Z�X�v�{�^��
	const Kokoha::Button ACCESS_BUTTON
	(
		U"�A�N�Z�X",
		Kokoha::getRectFromCenter(Point(320, 260), Size(100, 30))
	);
	// �u�����сv�{�^��
	const Kokoha::Button EQUIPMENT_BUTTON
	(
		U"������",
		Kokoha::getRectFromCenter(Point(320, 300), Size(100, 30))
	);

	// �{�^���̃��X�g
	const Array<Kokoha::Button> BUTTON_LIST
	{
		ACCESS_BUTTON,
		EQUIPMENT_BUTTON
	};

	// �J�[�\���̈ړ��̔�
	constexpr double RATE = 0.005;
}


std::unordered_map<String, int32> Kokoha::ChallengeStageWindow::sLevel;


Kokoha::ChallengeStageWindow::ChallengeStageWindow(const String& stageName)
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
	, mStageName(stageName)
	, mCursor(ACCESS_BUTTON.getRegion())
	, mSelectedButton(ACCESS_BUTTON.getRegion().pos, ACCESS_BUTTON.getName())
{
}


void Kokoha::ChallengeStageWindow::select()
{
	ButtonManager::instance().clearButtonList();

	// �{�^���̓o�^
	ButtonManager::instance().registerButton(ACCESS_BUTTON);
	ButtonManager::instance().registerButton(EQUIPMENT_BUTTON);
	ButtonManager::instance().setVerticalAdjacentButton
	(
		ACCESS_BUTTON.getName(),
		EQUIPMENT_BUTTON.getName()
	);

	// �{�^�����������Ƃ��̏����̐ݒ�
	ButtonManager::instance().setOnClickFunc
	(
		ACCESS_BUTTON.getName(),
		[this]() {
			GameManager::instance().setName(mStageName);
			AdventureManager::instance().setSceneName(SceneName::LOAD_GAME); 
			AdventureManager::instance().clearWindow();
		}
	);
	ButtonManager::instance().setOnClickFunc
	(
		EQUIPMENT_BUTTON.getName(),
		[]() { AdventureManager::instance().openWindow(std::make_unique<SetupWindow>()); }
	);

	ButtonManager::instance().setSelectedButton(mSelectedButton.second);
}


void Kokoha::ChallengeStageWindow::update()
{
	internalDividingPoint
	(
		mCursor.pos,
		mSelectedButton.first,
		RATE
	);
}


void Kokoha::ChallengeStageWindow::selectedUpdate()
{
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	mSelectedButton.first  = ButtonManager::instance().getSelectedButton().getRegion().pos;
	mSelectedButton.second = ButtonManager::instance().getSelectedButton().getName();
	ButtonManager::instance().update();
}


void Kokoha::ChallengeStageWindow::draw() const
{
	drawBoard();

	if (mStageName == U"5-1" || mStageName == U"5-2" || mStageName == U"5-3")
	{
		FontAsset(U"20")(U"���̃p�\�R���ɃA�N�Z�X���܂����H").drawAt(TEXT_POS, MyWhite);
	}
	else if (mStageName == U"Last")
	{
		FontAsset(U"20")(U"���̃h�A�ɃA�N�Z�X���܂����H").drawAt(TEXT_POS, MyWhite);
	}
	else
	{
		FontAsset(U"20")(U"���̃��{�b�g�ɃA�N�Z�X���܂����H").drawAt(TEXT_POS, MyWhite);
	}

	mCursor.draw(MyWhite);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = button.getName() == mSelectedButton.second
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}

	const int32 LEVEL_Y = 210;
	FontAsset(U"20")(U"��Փx").drawAt(200, LEVEL_Y, MyWhite);
	if (sLevel.count(mStageName))
	{
		const int32 LEVEL_X = 250;
		for (int32 i = 0; i < sLevel[mStageName]; ++i)
		{
			TextureAsset(U"Level").drawAt(LEVEL_X + i * 30, LEVEL_Y);
		}
	}
}


void Kokoha::ChallengeStageWindow::setLevel()
{
	sLevel[U"1-1"] = 1;
	sLevel[U"1-2"] = 3;
	sLevel[U"1-3"] = 6;

	sLevel[U"2-1"] = 1;
	sLevel[U"2-2"] = 4;
	sLevel[U"2-3"] = 5;

	sLevel[U"3-1"] = 1;
	sLevel[U"3-2"] = 3;
	sLevel[U"3-3"] = 5;

	sLevel[U"4-1"] = 2;
	sLevel[U"4-2"] = 3;
	sLevel[U"4-3"] = 6;

	sLevel[U"5-1"] = 2;
	sLevel[U"5-2"] = 4;
	sLevel[U"5-3"] = 5;

	sLevel[U"6-1"] = 2;
	sLevel[U"6-2"] = 4;
	sLevel[U"6-3"] = 6;

	sLevel[U"Last"]   = 7;
	sLevel[U"Kokoro"] = 8;
}
