#include "EventObject.h"


Kokoha::EventObject::EventObject(const Point& pos, const String& textureName, const Size& sliceSize, const Point& texturePos)
	: mPos(pos)
	, mLinearMove(0.0, pos, Vec2::Zero())
	, mSlide(textureName,sliceSize,texturePos)
	, mIsHidden(false)
	, mIsFinished(true)
{

}


void Kokoha::EventObject::update()
{
	mPos        = mLinearMove.getValue().asPoint();
	mIsFinished = mIsFinished | mLinearMove.update() | mSlide.changeTexture();
}


void Kokoha::EventObject::draw() const
{
	if (mIsHidden) { return; }

	mSlide.getTexture().draw(mPos);
}


void Kokoha::EventObject::setLinearMove(double time, const Point& movement, bool wait)
{
	mLinearMove = Linearly<Vec2>(time, mPos, movement);
	mIsFinished = !wait;
}

