#include "TitleScene.h"
#include "../MyColor.h"
#include "../MyLibrary.h"


namespace
{
	// ���S��`�悷����W
	constexpr Point LOGO_POS(320, 150);

	// ���̌`
	constexpr RoundRect LIGHT_SHAPE(-30, -30, 700, 540, 100);
	// ���̂ڂ����̑傫��
	constexpr double    LIGHT_BLUR = 120;
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
