#include "TestEventObject.h"


Kokoha::TestEventObject::TestEventObject(const Point& pos)
	: EventObject(pos, U"BoxRobot", Size(30, 30), Point::Zero())
{

}
