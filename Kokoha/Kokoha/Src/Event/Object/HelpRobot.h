#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	HelpRobotクラス
	EventObject
	お母さん
	*/
	class HelpRobot : public EventObject
	{
	public:

		HelpRobot(const Point& pos);

	};
}