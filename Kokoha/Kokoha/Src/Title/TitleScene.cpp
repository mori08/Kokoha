#include "TitleScene.h"
#include "../MyColor.h"
#include "../MyLibrary.h"
#include "../Input/ButtonManager.h"


namespace
{
	// �{�^���̃T�C�Y
	constexpr Size BUTTON_SIZE(150, 30);
	// NEWGAME�{�^��
	const Kokoha::Button NEWGAME_BUTTON (U"�͂��߂���", Rect(320 - BUTTON_SIZE.x / 2, 300, BUTTON_SIZE));
	// LOADGAME�{�^��
	const Kokoha::Button LOADGAME_BUTTON(U"�Â�����", Rect(320 - BUTTON_SIZE.x / 2, 350, BUTTON_SIZE));
	// EXIT�{�^��
	const Kokoha::Button EXIT_BUTTON    (U"��߂�"    , Rect(320 - BUTTON_SIZE.x / 2, 400, BUTTON_SIZE));
	// �{�^���̃��X�g
	const Array<Kokoha::Button> BUTTON_LIST
	{
		NEWGAME_BUTTON,
		LOADGAME_BUTTON,
		EXIT_BUTTON
	};

	// �J�[�\���̈ړ��̔�
	constexpr double CURSOR_RATE = 0.005;

	// ���S��`�悷����W
	constexpr Point LOGO_POS(320, 150);

	// ���̌`
	constexpr RoundRect LIGHT_SHAPE(-50, -50, 740, 580, 100);
	// ���̂ڂ����̑傫��
	constexpr double    LIGHT_BLUR = 140;
	// ���̂ڂ�����ύX����p�x
	constexpr double    LIGHT_SPREAD_FREQUENCY = 3;

	// ��(�m�C�Y�̂悤�ȉ��o)��`�悷��p�x
	constexpr double LINE_FREQUENCY = 2;
	// ���̕�
	constexpr int32  LINE_WIDTH = 1;
	// ���̕s�����x
	constexpr int32  LINE_ALPHA = 0x40;
}


Kokoha::TitleScene::TitleScene(const InitData& init)
	: IScene(init)
	, mCursor(NEWGAME_BUTTON.getRegion())
{
	// �{�^���̃��Z�b�g
	ButtonManager::instance().clearButtonList();

	// �{�^���̐ݒ�
	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	// �{�^���̈ʒu�֌W�̐ݒ�
	ButtonManager::instance().setVerticalAdjacentButton
	(
		NEWGAME_BUTTON.getName(),
		LOADGAME_BUTTON.getName()
	);
	ButtonManager::instance().setVerticalAdjacentButton
	(
		LOADGAME_BUTTON.getName(),
		EXIT_BUTTON.getName()
	);

	// �{�^���ɉ������Ƃ��̏����̐ݒ�
	ButtonManager::instance().setOnClickFunc
	(
		NEWGAME_BUTTON.getName(), 
		[this]() { changeScene(SceneName::LOAD_RECORD); }
	);
	ButtonManager::instance().setOnClickFunc
	(
		LOADGAME_BUTTON.getName(),
		[this]() { changeScene(SceneName::SAVE_RECORD); }
	);

	// �I�𒆂̃{�^���̐ݒ�
	ButtonManager::instance().setSelectedButton(NEWGAME_BUTTON.getName());
}


void Kokoha::TitleScene::update()
{
	// �J�[�\���̈ړ�
	internalDividingPoint
	(
		mCursor.pos, 
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_RATE
	);
	
	// �{�^���̍X�V
	ButtonManager::instance().update();
}


void Kokoha::TitleScene::draw() const
{
	// ���̕`��
	LIGHT_SHAPE.drawShadow
	(
		Vec2::Zero(),
		LIGHT_BLUR,
		randomFrequency(LIGHT_SPREAD_FREQUENCY),
		MyWhite
	);

	// ���S�̕`��
	TextureAsset(U"Logo").drawAt(LOGO_POS);

	// �{�^���ƃJ�[�\���̕`��
	mCursor.draw(MyBlack);
	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == ButtonManager::instance().getSelectedButton().getName())
			? MyWhite
			: MyBlack;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}

	// ��(�m�C�Y�̂悤�ȉ��o)��`��
	if (randomFrequency(LINE_FREQUENCY))
	{
		Rect(0, Random(Scene::Height()), Scene::Width(), LINE_WIDTH).draw(Color(MyBlack, LINE_ALPHA));
	}
}
