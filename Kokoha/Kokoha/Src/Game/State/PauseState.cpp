#include "PauseState.h"
#include "PlayingState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"
#include "../../Input/ButtonManager.h"


namespace
{
	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(150, 30);

	// �u�Â���v�{�^��
	const Kokoha::Button CONTINUE_BUTTON
	(
		U"�Â���",
		Kokoha::getRectFromCenter(Point(320, 300), BUTTON_SIZE)
	);
	// �u���Ȃ����v�{�^��
	const Kokoha::Button RELOAD_BUTTON
	(
		U"���Ȃ���",
		Kokoha::getRectFromCenter(Point(320, 350), BUTTON_SIZE)
	);
	// �u������߂�v�{�^��
	const Kokoha::Button GIVEUP_BUTTON
	(
		U"������߂�",
		Kokoha::getRectFromCenter(Point(320, 400), BUTTON_SIZE)
	);

	// �{�^�����X�g
	const Array<Kokoha::Button> BUTTON_LIST
	{
		CONTINUE_BUTTON,
		RELOAD_BUTTON,
		GIVEUP_BUTTON
	};

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.005;

	// �e�L�X�g�̕\��
	constexpr Point TEXT_POS(320, 150);
}



Kokoha::PauseState::PauseState(std::unique_ptr<GameState> preState)
	: mPreState(std::move(preState))
	, mSceneName(none)
	, mCursor(CONTINUE_BUTTON.getRegion())
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	// �{�^���̐ݒ�
	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	// �{�^���̈ʒu�֌W�̐ݒ�
	for (size_t i = 0; i < BUTTON_LIST.size(); ++i)
	{
		ButtonManager::instance().setVerticalAdjacentButton
		(
			BUTTON_LIST[i].getName(),
			BUTTON_LIST[(i + 1) % BUTTON_LIST.size()].getName()
		);
	}

	// �{�^�����������Ƃ��̏����̐ݒ�
	ButtonManager::instance().setOnClickFunc
	(
		CONTINUE_BUTTON.getName(),
		[this]() { GameManager::instance().setState(std::move(mPreState)); }
	);
	ButtonManager::instance().setOnClickFunc
	(
		RELOAD_BUTTON.getName(),
		[this]() { mSceneName = SceneName::LOAD_GAME; }
	);
	ButtonManager::instance().setOnClickFunc
	(
		GIVEUP_BUTTON.getName(),
		[this]() { mSceneName = SceneName::ADVENTURE; }
	);

	// �I�𒆂̃{�^���̐ݒ�
	ButtonManager::instance().setSelectedButton(CONTINUE_BUTTON.getName());
}


void Kokoha::PauseState::update()
{
	// �J�[�\���̈ړ�
	internalDividingPoint
	(
		mCursor.pos,
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_RATE
	);

	// �L�����Z���{�^���ő�����
	if (InputManager::instance().cancel())
	{
		GameManager::instance().setState(std::move(mPreState));
		return;
	}

	// �{�^���̍X�V
	ButtonManager::instance().update();
}


void Kokoha::PauseState::draw() const
{
	mCursor.draw(MyWhite);

	FontAsset(U"30")(U"�|�[�Y").drawAt(TEXT_POS, MyWhite);

	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == ButtonManager::instance().getSelectedButton().getName())
			? MyBlack
			: MyWhite;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}


Optional<SceneName> Kokoha::PauseState::isChangeAbleScene() const
{
	return mSceneName;
}
