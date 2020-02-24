#include "DoctorReport.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"


namespace
{
	// 光の形
	constexpr RoundRect LIGHT_SHAPE(-50, -50, 740, 420, 100);
	// 光のぼかしの大きさ
	constexpr double    LIGHT_BLUR = 140;
	// 光のぼかしを変更する頻度
	constexpr double    LIGHT_SPREAD_FREQUENCY = 3;

	// 線(ノイズのような演出)を描画する頻度
	constexpr double LINE_FREQUENCY = 2;
	// 線の幅
	constexpr int32  LINE_WIDTH = 1;
	// 線の不透明度
	constexpr int32  LINE_ALPHA = 0x40;

	// 点を描画する頻度
	constexpr double POINT_FREQUENCY = 10.0;
}


Kokoha::DoctorReport::DoctorReport(const Point& pos)
	: EventObject(pos, U"", Size::One(), Point::Zero())
{
}


void Kokoha::DoctorReport::draw(const Point&) const
{
	Scene::Rect().draw(MyBlack);

	// 光の描画
	LIGHT_SHAPE.drawShadow
	(
		Vec2::Zero(),
		LIGHT_BLUR,
		randomFrequency(LIGHT_SPREAD_FREQUENCY),
		MyWhite
	);

	// 点の頻度
	for(int32 i=0;i<10;++i)
		if (randomFrequency(POINT_FREQUENCY))
		{
			RectF(RandomVec2(RectF(Vec2::Zero(), Vec2(640, 320))), 1 * Vec2::One()).draw(MyBlack);
		}

	// 線(ノイズのような演出)を描画
	if (randomFrequency(LINE_FREQUENCY))
	{
		Rect(0, Random(Scene::Height()), Scene::Width(), LINE_WIDTH).draw(Color(MyBlack, LINE_ALPHA));
	}
}
