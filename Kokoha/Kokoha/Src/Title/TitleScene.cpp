#include "TitleScene.h"
#include "../MyColor.h"
#include "../MyLibrary.h"


namespace
{
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
{

}


void Kokoha::TitleScene::update()
{

}


void Kokoha::TitleScene::draw() const
{
	LIGHT_SHAPE.drawShadow
	(
		Vec2::Zero(),
		LIGHT_BLUR,
		randomFrequency(LIGHT_SPREAD_FREQUENCY),
		MyWhite
	);

	TextureAsset(U"Logo").drawAt(LOGO_POS);

	if (randomFrequency(LINE_FREQUENCY))
	{
		Rect(0, Random(Scene::Height()), Scene::Width(), LINE_WIDTH).draw(Color(MyBlack, LINE_ALPHA));
	}
}
