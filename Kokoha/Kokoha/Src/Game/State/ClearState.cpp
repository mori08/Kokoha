#include "ClearState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"
#include "../../Record/RecordManager.h"


namespace
{
	// �A���t�@�l�̕ύX�̔�
	constexpr double CHANGE_ALPHA_RATE = 0.1;

	// ����\�����n�߂鎞��
	constexpr double LIGHT_START_SECOND = 1.0;
	// ���̈ړ��̔�
	constexpr double LIGHT_MOVE_RATE = 0.3;
	// ���̒��S�Ƃ̋����̍ő�l
	constexpr double MAX_RADIUS = 200.0;
	// ���͈̔�
	constexpr RoundRect LIGHT_REGION(Point(320, 240) - Size(240, 60) / 2, Size(240, 60), 10);
	// ���̍L�����
	constexpr double LIGHT_BLUR = 10.0;
	// ���̐�
	constexpr int32 LIGHT_NUM = 12;

	// �V�[���J��
	constexpr double CHANGE_SCENE_SECOND = 5.0;
}


Kokoha::ClearState::ClearState()
	: mTimeSecond(0)
	, mBackAlpha(0)
	, mLightAlpha(0)
	, mRadius(0)
{
	RecordManager::instance().setRecord(GameManager::instance().getName(), 1);
}


void Kokoha::ClearState::update()
{
	// ���Ԍo��
	mTimeSecond += Scene::DeltaTime();

	// �w�i�̃A���t�@�l�̕ύX
	internalDividingPoint(mBackAlpha, 1.0, CHANGE_ALPHA_RATE);

	if (mTimeSecond < LIGHT_START_SECOND) { return; }

	// ���̃A���t�@�l�̕ύX
	internalDividingPoint(mLightAlpha, 1.0, CHANGE_ALPHA_RATE);
	
	// ���̕`��ʒu�̕ύX
	internalDividingPoint(mRadius, MAX_RADIUS, LIGHT_MOVE_RATE);
}


void Kokoha::ClearState::draw() const
{
	GameManager::instance().draw();

	const ColorF black = ColorF(MyBlack).setA(mBackAlpha);
	const ColorF white = ColorF(MyWhite).setA(mLightAlpha);

	// �w�i����������������
	Scene::Rect().draw(black);

	if (mTimeSecond < LIGHT_START_SECOND) { return; }

	// ���S�𖾂邭
	LIGHT_REGION.drawShadow(Vec2::Zero(), LIGHT_BLUR, 0, white);

	// �e�L�X�g�̕\��
	FontAsset(U"40")(U"SUCCESS").drawAt(Scene::CenterF(), black);

	// ���̋ʂ𒆐S����Ƃ΂�
	for (int32 i = 0; i < LIGHT_NUM; ++i)
	{
		const double angle = Math::TwoPi * i / LIGHT_NUM;
		const Vec2   direction(Sin(angle), Cos(angle));

		Circle(Scene::CenterF() + mRadius * direction, 10)
			.drawShadow(Vec2::Zero(), 10, 0, white);
	}
}


Optional<SceneName> Kokoha::ClearState::isChangeAbleScene() const
{
	if (mTimeSecond < CHANGE_SCENE_SECOND) { return none; }

	return SceneName::ADVENTURE;
}
