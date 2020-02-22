#include "AwakeState.h"
#include "../../GameManager.h"
#include "../../../MyColor.h"
#include "../../../MyLibrary.h"


namespace
{
	// �V�[���J�ڎ���
	constexpr double CHANGE_SCENE_TIME = 4.0;
}


Kokoha::AwakeState::AwakeState()
	: mTimeSecond(0)
	, mBackAlpha(0)
{
}


void Kokoha::AwakeState::update()
{
	mTimeSecond += Scene::DeltaTime();
	
	internalDividingPoint
	(
		mBackAlpha,
		1.0,
		0.01
	);
}


void Kokoha::AwakeState::draw() const
{
	GameManager::instance().draw();

	Scene::Rect().draw(ColorF(MyBlack).setA(mBackAlpha));

	FontAsset(U"20")(U"�N����...")
		.drawAt(Scene::Center(), ColorF(MyWhite).setA(mBackAlpha));

	// �Q�[�W
	getRectFromCenter
	(
		Scene::Center() + Point(0, -11),
		Size((int32)(640 * mTimeSecond / CHANGE_SCENE_TIME), 2)
	).draw(MyWhite);
	getRectFromCenter
	(
		Scene::Center() + Point(0, +11),
		Size((int32)(640 * mTimeSecond / CHANGE_SCENE_TIME), 2)
	).draw(MyWhite);
}


Optional<SceneName> Kokoha::AwakeState::isChangeAbleScene() const
{
	if (mTimeSecond > CHANGE_SCENE_TIME)
	{
		return SceneName::TITLE;
	}

	return none;
}
