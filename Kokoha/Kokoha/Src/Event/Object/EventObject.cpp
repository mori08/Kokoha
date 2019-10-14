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


void Kokoha::EventObject::draw(const Point& cameraPos) const
{
	if (mIsHidden) { return; }

	mSlide.getTexture().draw(mPos + cameraPos);
}


void Kokoha::EventObject::setLinearMove(double time, const Point& movement, bool wait)
{
	// à⁄ìÆéûä‘Ç‚à⁄ìÆó ÇÃï‚ê≥
	const Point  m = movement + mLinearMove.getGoal().asPoint() - mPos;
	const double t = time * m.length() / movement.length();

	mLinearMove = Linearly<Vec2>(t, mPos, movement + mLinearMove.getGoal().asPoint() - mPos);
	mIsFinished = !wait;
}

