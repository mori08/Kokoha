#include "ClearState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"


namespace
{
	// �t�H���g��
	const String FONT_NAME = U"30";
	// �\���e�L�X�g
	const String TEXT = U"SUCCESS";

	// �A���t�@�l��ύX���銄��
	constexpr double ALPHA_CHANGE_RATE = 0.1;

	// ���̈ړ��̊���
	constexpr double LIGHT_MOVE_RATE = 0.01;
	// �����o������(s)
	constexpr double LIGHT_MOVE_SECOND = 1.0;

	// �����o������(s)
	constexpr double LINE_SECOND = 1.2;
	// �����o���p�x(/s)
	constexpr double LINE_FREQUENCY = 6.0;

	// �V�[���J�ڂ��鎞��(s)
	constexpr double CHANGE_SCENE_SECOND = 5.0;
}


Kokoha::ClearState::ClearState()
	: LIGHT_SIZE(1.5*FontAsset(FONT_NAME)(TEXT).region().size)
	, mTimeSecond(0)
	, mAlpha(0)
{
	mLight[0] = RectF
	(
		Scene::Width(),
		Scene::CenterF().y - LIGHT_SIZE.y / 2.0,
		LIGHT_SIZE.x,
		LIGHT_SIZE.y / 2
	);
	mLight[1] = RectF
	(
		-LIGHT_SIZE.x,
		Scene::CenterF().y,
		LIGHT_SIZE.x,
		LIGHT_SIZE.y / 2
	);
}


void Kokoha::ClearState::update()
{
	// ���Ԍo��
	mTimeSecond += Scene::DeltaTime();

	// �w�i�̃A���t�@�l�̕ύX
	internalDividingPoint(mAlpha, 1.0, ALPHA_CHANGE_RATE);

	if (mTimeSecond < LIGHT_MOVE_SECOND) { return; }

	// ���̈ړ�
	for (auto& light : mLight)
	{
		internalDividingPoint
		(
			light.x,
			Scene::CenterF().x - LIGHT_SIZE.x/2,
			LIGHT_MOVE_RATE
		);
	}
}


void Kokoha::ClearState::draw() const
{
	GameManager::instance().draw();

	const ColorF black = ColorF(MyBlack).setA(mAlpha);

	Scene::Rect().draw(black);

	for (const auto& light : mLight)
	{
		light.draw(MyWhite);
	}

	if (randomFrequency(LINE_FREQUENCY))
	{
		Point pos
		(
			Random(0, 1) * Scene::Center().x,
			Scene::Center().y + Random(-1, +1) * (int32)Random(LIGHT_SIZE.y / 2)
		);
		Rect(pos, Scene::Center().x, 1).draw(MyWhite);
	}

	FontAsset(FONT_NAME)(TEXT).drawAt(Scene::CenterF(), black);
}


Optional<SceneName> Kokoha::ClearState::isChangeAbleScene() const
{
	if (mTimeSecond < CHANGE_SCENE_SECOND) { return none; }

	return SceneName::LOAD_ADVENTURE;
}
