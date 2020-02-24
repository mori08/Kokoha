#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	EventEffectクラス
	暗転やノイズ演出を行うEventObject
	*/
	class EventEffect : public EventObject
	{
	private:

		// trueのときノイズ
		bool mNoise;

		// trueのとき暗転
		bool mDark;

		// 暗転時のアルファ値
		double mDarkAlpha;

	public:

		EventEffect(const Point& pos);

	private:

		void update() override;

		void draw(const Point& cameraPos) const override;

	};
}