#include "DoctorReport.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"


namespace
{
	// ���̌`
	constexpr RoundRect LIGHT_SHAPE(-50, -50, 740, 420, 100);
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

	// �_��`�悷��p�x
	constexpr double POINT_FREQUENCY = 10.0;
}


Kokoha::DoctorReport::DoctorReport(const Point& pos)
	: EventObject(pos, U"", Size::One(), Point::Zero())
{
}


void Kokoha::DoctorReport::draw(const Point&) const
{
	Scene::Rect().draw(MyBlack);

	// ���̕`��
	LIGHT_SHAPE.drawShadow
	(
		Vec2::Zero(),
		LIGHT_BLUR,
		randomFrequency(LIGHT_SPREAD_FREQUENCY),
		MyWhite
	);

	// �_�̕p�x
	for(int32 i=0;i<10;++i)
		if (randomFrequency(POINT_FREQUENCY))
		{
			RectF(RandomVec2(RectF(Vec2::Zero(), Vec2(640, 320))), 1 * Vec2::One()).draw(MyBlack);
		}

	// ��(�m�C�Y�̂悤�ȉ��o)��`��
	if (randomFrequency(LINE_FREQUENCY))
	{
		Rect(0, Random(Scene::Height()), Scene::Width(), LINE_WIDTH).draw(Color(MyBlack, LINE_ALPHA));
	}
}
