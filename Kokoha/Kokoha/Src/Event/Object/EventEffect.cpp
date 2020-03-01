#include "EventEffect.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"


namespace
{
	// 暗転の比率
	constexpr double DARK_RATE = 0.01;

	// マスの1辺の長さ
	constexpr int32 SQUARE_SIZE = 32;
	// マスの振動範囲
	constexpr Rect SHAKE_RANGE = Kokoha::getRectFromTwoPoint(Point(-1, -1), Point(+1, +1));
}


Kokoha::EventEffect::EventEffect(const Point& pos)
	: EventObject(pos, U"", Point::One(), Point::Zero())
	, mNoise(false)
	, mDark(false)
	, mDarkAlpha(0)
{
	mActMap[U"Noise"] = [this]() { changeNoise(); };
	mActMap[U"Dark" ] = [this]() { changeDark();  };
}


void Kokoha::EventEffect::update()
{
	internalDividingPoint
	(
		mDarkAlpha,
		mDark ? 1.0 : 0.0,
		DARK_RATE
	);
}


void Kokoha::EventEffect::draw(const Point&) const
{
	Scene::Rect().draw(ColorF(MyBlack).setA(mDarkAlpha));
	
	if (mNoise)
	{
		for (auto pos : getGridPoint(Rect(Point::Zero(), Scene::Size() / SQUARE_SIZE)))
		{
			Rect(SQUARE_SIZE * pos + RandomPoint(SHAKE_RANGE), SQUARE_SIZE)
				.draw(MyBlack);
		}
	}
}
