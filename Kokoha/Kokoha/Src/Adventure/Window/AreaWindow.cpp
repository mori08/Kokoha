#include "AreaWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"
#include "../../Record/RecordManager.h"
#include "../../Input/ButtonManager.h"


namespace
{
	// �E�B���h�E�̃T�C�Y
	constexpr Size WINDOW_SIZE(150, 300);

	// �{�^���̐�
	constexpr int32 BUTTON_NUM = 7;

	// �t���O�Ǘ�
	const Array<std::function<bool()>> AREA_FLAG
	{
		[]() { return true; },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"1-1"); },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"3-1"); },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"4-1"); },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"3-2") && Kokoha::RecordManager::instance().getRecord(U"1-2"); },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"3-3"); },
		[]() { return Kokoha::RecordManager::instance().getRecord(U"2-1"); }
	};

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(120, 30);

	// �{�^���̊���W
	constexpr Point BUTTON_BASE_POS(320, 180);

	// �{�^���̖��O
	const Array<String> BUTTON_NAME
	{
		U"�q��",
		U"������",
		U"������",
		U"�n�J�Z�̕���",
		U"�S�~�̂ď�",
		U"�󂫕���",
		U"����"
	};

	// �J�[�\���ړ��̔�
	constexpr double RATE = 0.001;
}


Kokoha::AreaWindow::AreaWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
{
	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		if (!AREA_FLAG[i]()) { continue; }

		mAlphaMap[BUTTON_NAME[i]] = 0x80;

		Button button
		(
			BUTTON_NAME[i],
			getRectFromCenter(BUTTON_BASE_POS + Point(0, i * BUTTON_SIZE.y), BUTTON_SIZE)
		);

		if (i == AdventureManager::instance().getAreaId()) 
		{
			mButtonList.emplace_back(button);
			continue; 
		}

		mAlphaMap[BUTTON_NAME[i]] = 0xFF;

		button.setOnClickFunc
		(
			[i]()
			{
				AdventureManager::instance().setAreaId(i);
				AdventureManager::instance().setSceneName(SceneName::LOAD_ADVENTURE);
				AdventureManager::instance().clearWindow();
			}
		);

		mButtonList.emplace_back(button);
	}
}


void Kokoha::AreaWindow::select()
{
	ButtonManager::instance().clearButtonList();

	if (mButtonList.empty()) { return; }

	// �{�^���̓o�^
	for (const auto& button : mButtonList)
	{
		ButtonManager::instance().registerButton(button);
	}

	// �ʒu�֌W�̐ݒ�
	for (int32 i = 0; i < mButtonList.size(); ++i)
	{
		ButtonManager::instance().setVerticalAdjacentButton
		(
			mButtonList[i].getName(),
			mButtonList[(i+1) % (int32)mButtonList.size()].getName()
		);
	}

	ButtonManager::instance().setSelectedButton(mButtonList[0].getName());

	// �J�[�\���̏����ݒ�
	mCursor = mButtonList[0].getRegion();
}


void Kokoha::AreaWindow::update()
{
	if (mButtonList.empty()) { return; }

	internalDividingPoint
	(
		mCursor.pos,
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		RATE
	);
}


void Kokoha::AreaWindow::selectedUpdate()
{
	// �E�B���h�E�����
	if (InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
		return;
	}

	// �ړ��ł���G���A���Ȃ��Ƃ�
	if (mButtonList.empty())
	{
		if (InputManager::instance().decision())
		{
			AdventureManager::instance().closeWindow();
		}
		return;
	}

	ButtonManager::instance().update();
}


void Kokoha::AreaWindow::draw() const
{
	drawBoard();

	// �ړ��ł���G���A���Ȃ��Ƃ�
	if (mButtonList.empty())
	{
		FontAsset(U"20")(U"�܂��p�͂Ȃ�.").drawAt(Scene::Center(), MyWhite);
		return;
	}

	mCursor.draw(MyWhite);


	FontAsset(U"20")(U"�ǂ��ɍs���H").drawAt(Point(320, 120));

	for (const auto& button : mButtonList)
	{
		Color color = (button.getName() == ButtonManager::instance().getSelectedButton().getName())
			? MyBlack
			: MyWhite;

		color.setA(mAlphaMap.find(button.getName())->second);

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}
