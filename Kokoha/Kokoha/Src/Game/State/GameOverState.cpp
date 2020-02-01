#include "GameOverState.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"
#include "../../Input/ButtonManager.h"


namespace
{
	// �A���t�@�l�ύX�̔�
	constexpr double CHANGE_ALPHA_RATE = 0.05;

	// �}�X��1�ӂ̒���
	constexpr int32 SQUARE_SIZE = 32;
	// �}�X�̐U���͈�
	constexpr Rect SHAKE_RANGE = Kokoha::getRectFromTwoPoint(Point(-1, -1), Point(+1, +1));

	// �e�L�X�g��\�����n�߂鎞��
	constexpr double DRAW_TEXT_START = 1.2;
	// ���̕�����\������܂ł̊���
	constexpr double DRAW_TEXT_SPAN  = 0.18;

	// �I���\�ɂȂ鎞��
	constexpr double SELECT_SECOND = 2.0;
	// �I���E�B���h�E
	constexpr RoundRect SELECT_WINDOW
	(
		Vec2(550, 400) - Vec2(150, 100)/2,
		Vec2(150, 100),
		5
	);

	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(120, 30);
	// �u������x�v�{�^��
	const Kokoha::Button CONTINUE_BUTTON(U"����������", Kokoha::getRectFromCenter(Point(550, 380), BUTTON_SIZE));
	// �u������߂�v�{�^��
	const Kokoha::Button GIVEUP_BUTTON  (U"������߂�", Kokoha::getRectFromCenter(Point(550, 420), BUTTON_SIZE));
	// �{�^���̃��X�g
	const Array<Kokoha::Button> BUTTON_LIST
	{
		CONTINUE_BUTTON,
		GIVEUP_BUTTON
	};
	// �J�[�\���𓮂�����
	constexpr double CURSOR_MOVE_RATE = 0.001;
}


Kokoha::GameOverState::GameOverState()
	: mTimeSecond(0)
	, mSquareAlpha(0)
	, mSceneName(none)
	, mCursor(CONTINUE_BUTTON.getRegion())
{
	ButtonManager::instance().clearButtonList();
	for (auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	ButtonManager::instance().setOnClickFunc
	(
		CONTINUE_BUTTON.getName(),
		[this]()
		{
			mSceneName = SceneName::LOAD_GAME;
		}
	);

	ButtonManager::instance().setOnClickFunc
	(
		GIVEUP_BUTTON.getName(),
		[this]()
		{
			mSceneName = SceneName::LOAD_ADVENTURE;
		}
	);

	ButtonManager::instance().setVerticalAdjacentButton
	(
		CONTINUE_BUTTON.getName(),
		GIVEUP_BUTTON.getName()
	);
}


void Kokoha::GameOverState::update()
{
	mTimeSecond += Scene::DeltaTime();

	// �}�X�̃A���t�@�l�̕ύX
	internalDividingPoint(mSquareAlpha, 1.0, CHANGE_ALPHA_RATE);

	if (mTimeSecond < DRAW_TEXT_START) { return; }

	// �{�^���̍X�V
	ButtonManager::instance().update();
	internalDividingPoint
	(
		mCursor.pos,
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_MOVE_RATE
	);
}


void Kokoha::GameOverState::draw() const
{
	// �w�i�̔�
	Scene::Rect().draw(MyWhite);
	
	// �h���}�X
	for (auto pos : getGridPoint(Rect(Point::Zero(), Scene::Size() / SQUARE_SIZE)))
	{
		Rect(SQUARE_SIZE * pos + RandomPoint(SHAKE_RANGE), SQUARE_SIZE)
			.draw(ColorF(MyBlack).setA(mSquareAlpha));
	}

	if (mTimeSecond < DRAW_TEXT_START) { return; }

	// �e�L�X�g�̕\��
	const size_t textLength = (size_t)((mTimeSecond - DRAW_TEXT_START) / DRAW_TEXT_SPAN);
	const String text = String(U"FAILED").substr(0, textLength);
	FontAsset(U"40")(text).drawAt(Scene::CenterF(), MyWhite);

	if (mTimeSecond < SELECT_SECOND) { return; }

	// �V�[���J�ڐ�̑I��
	SELECT_WINDOW.draw(MyBlack).drawFrame(2.0, MyWhite);
	mCursor.draw(MyWhite);
	for (const auto& button : BUTTON_LIST)
	{
		Color color = ButtonManager::instance().getSelectedButton().getName() == button.getName()
			? MyBlack
			: MyWhite;
		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}
}


Optional<SceneName> Kokoha::GameOverState::isChangeAbleScene() const
{
	return mSceneName;
}
