#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	DoctorReportクラス
	EventObject
	ノイズを流す
	*/
	class DoctorReport : public EventObject
	{
	public:

		DoctorReport(const Point& pos);

	private:

		void draw(const Point& cameraPos) const override;

	};
}