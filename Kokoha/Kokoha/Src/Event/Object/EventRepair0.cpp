#include "EventRepair0.h"


namespace 
{
	// �摜�̃T�C�Y
	constexpr Size TEXTURE_SIZE(100, 100);
}


Kokoha::EventRepair0::EventRepair0(const Point& pos)
	: EventObject(pos, U"Repair0", TEXTURE_SIZE, Point::Zero())
{
}
