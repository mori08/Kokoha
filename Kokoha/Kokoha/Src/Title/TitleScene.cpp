#include "TitleScene.h"
#include "../MyColor.h"
#include "../MyLibrary.h"
#include "../Input/ButtonManager.h"


namespace
{
	// ボタンのサイズ
	constexpr Size BUTTON_SIZE(150, 30);
	// NEWGAMEボタン
	const Kokoha::Button NEWGAME_BUTTON (U"NEW GAME" , Rect(320 - BUTTON_SIZE.x / 2, 300, BUTTON_SIZE));
	// LOADGAMEボタン
	const Kokoha::Button LOADGAME_BUTTON(U"LOAD GAME", Rect(320 - BUTTON_SIZE.x / 2, 350, BUTTON_SIZE));
	// EXITボタン
	const Kokoha::Button EXIT_BUTTON    (U"EXIT"     , Rect(320 - BUTTON_SIZE.x / 2, 400, BUTTON_SIZE));
	// ボタンのリスト
	const Array<Kokoha::Button> BUTTON_LIST
	{
		NEWGAME_BUTTON,
		LOADGAME_BUTTON,
		EXIT_BUTTON
	};

	// カーソルの移動の比
	constexpr double CURSOR_RATE = 0.005;

	// ロゴを描画する座標
	constexpr Point LOGO_POS(320, 150);

	// 光の形
	constexpr RoundRect LIGHT_SHAPE(-30, -30, 700, 540, 100);
	// 光のぼかしの大きさ
	constexpr double    LIGHT_BLUR = 120;
	// 光のぼかしを変更する頻度
	constexpr double    LIGHT_SPREAD_FREQUENCY = 3;

	// 線(ノイズのような演出)を描画する頻度
	constexpr double LINE_FREQUENCY = 2;
	// 線の幅
	constexpr int32  LINE_WIDTH = 1;
	// 線の不透明度
	constexpr int32  LINE_ALPHA = 0x40;
}


Kokoha::TitleScene::TitleScene(const InitData& init)
	: IScene(init)
	, mCursor(NEWGAME_BUTTON.getRegion())
{
	ButtonManager::instance().clearButtonList();

	for (const auto& button : BUTTON_LIST)
	{
		ButtonManager::instance().registerButton(button);
	}

	ButtonManager::instance().setSelectedButton(NEWGAME_BUTTON.getName());
}


void Kokoha::TitleScene::update()
{
	// カーソルの移動
	internalDividingPoint
	(
		mCursor.pos, 
		ButtonManager::instance().getSelectedButton().getRegion().pos,
		CURSOR_RATE
	);
	
	// ボタンの更新
	ButtonManager::instance().update();
}


void Kokoha::TitleScene::draw() const
{
	// 光の描画
	LIGHT_SHAPE.drawShadow
	(
		Vec2::Zero(),
		LIGHT_BLUR,
		randomFrequency(LIGHT_SPREAD_FREQUENCY),
		MyWhite
	);

	// ロゴの描画
	TextureAsset(U"Logo").drawAt(LOGO_POS);

	// ボタンとカーソルの描画
	mCursor.draw(MyBlack);
	for (const auto& button : BUTTON_LIST)
	{
		Color color = (button.getName() == ButtonManager::instance().getSelectedButton().getName())
			? MyWhite
			: MyBlack;

		FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
	}

	// 線(ノイズのような演出)を描画
	if (randomFrequency(LINE_FREQUENCY))
	{
		Rect(0, Random(Scene::Height()), Scene::Width(), LINE_WIDTH).draw(Color(MyBlack, LINE_ALPHA));
	}
}
