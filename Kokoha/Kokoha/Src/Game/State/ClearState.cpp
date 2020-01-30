#include "ClearState.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"


namespace
{
	// フォント名
	const String FONT_NAME = U"30";
	// 表示テキスト
	const String TEXT = U"SUCCESS";

	// アルファ値を変更する割合
	constexpr double ALPHA_CHANGE_RATE = 0.1;

	// 光の移動の割合
	constexpr double LIGHT_MOVE_RATE = 0.01;
	// 光を出す時間(s)
	constexpr double LIGHT_MOVE_SECOND = 1.0;

	// 線を出す時間(s)
	constexpr double LINE_SECOND = 1.2;
	// 光を出す頻度(/s)
	constexpr double LINE_FREQUENCY = 6.0;

	// シーン遷移する時間(s)
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
	// 時間経過
	mTimeSecond += Scene::DeltaTime();

	// 背景のアルファ値の変更
	internalDividingPoint(mAlpha, 1.0, ALPHA_CHANGE_RATE);

	if (mTimeSecond < LIGHT_MOVE_SECOND) { return; }

	// 光の移動
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
