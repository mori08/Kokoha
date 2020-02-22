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
	constexpr Size WINDOW_SIZE(360, 150);

	// �e�L�X�g��\��������W
	constexpr Point TEXT_POS(320, 190);

	// �u�A�N�Z�X�v�{�^��
	const Kokoha::Button ACCESS_BUTTON
	(
		U"�A�N�Z�X",
		Kokoha::getRectFromCenter(Point(320, 250), Size(100, 30))
	);
	// �u�����сv�{�^��
	const Kokoha::Button EQUIPMENT_BUTTON
	(
		U"������",
		Kokoha::getRectFromCenter(Point(320, 290), Size(100, 30))
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
}
