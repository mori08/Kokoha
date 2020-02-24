#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	DoctorReport�N���X
	EventObject
	�m�C�Y�𗬂�
	*/
	class DoctorReport : public EventObject
	{
	public:

		DoctorReport(const Point& pos);

	private:

		void draw(const Point& cameraPos) const override;

	};
}