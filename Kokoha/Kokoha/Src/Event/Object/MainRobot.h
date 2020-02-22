#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	MainRobotクラス
	EventObject
	主役ロボット
	*/
	class MainRobot : public EventObject
	{
	public:

		MainRobot(const Point& pos);

	};
}