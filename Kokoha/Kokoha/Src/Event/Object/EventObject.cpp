#include "EventObject.h"


Kokoha::EventObject::EventObject(const Point& pos, const String& textureName, const Size& sliceSize, const Point& texturePos)
	: mPos(pos)
	, mLinearMove(0.0, pos, Vec2::Zero())
	, mSlide(textureName,sliceSize,texturePos)
	, mIsHidden(false)
	, mIsFinished(true)
{
	mActMap[U"Mirror"] = [this]() { mSlide.mirror();   };
	mActMap[U"Hide"]   = [this]() { mIsHidden = true;  };
	mActMap[U"Appear"] = [this]() { mIsHidden = false; };
}


void Kokoha::EventObject::update()
{
	mPos        = mLinearMove.getValue().asPoint();

	bool moveFlag = mLinearMove.update(), slideFlag = mSlide.changeTexture();
	mIsFinished = mIsFinished || (moveFlag && slideFlag);
}


void Kokoha::EventObject::draw(const Point& cameraPos) const
{
	if (mIsHidden) { return; }

	mSlide.getTexture().draw(mPos + cameraPos);
}


void Kokoha::EventObject::setLinearMove(double time, const Point& movement, bool wait)
{
	// �ړ����Ԃ�ړ��ʂ̕␳
	const Point  m = movement + mLinearMove.getGoal().asPoint() - mPos;
	const double t = time * m.length() / movement.length();

	mLinearMove = Linearly<Vec2>(t, mPos, movement + mLinearMove.getGoal().asPoint() - mPos);
	mIsFinished = !wait;
}


void Kokoha::EventObject::setAnimation(const String& animName, const Animation& anim)
{
	mSlide.setAnimation(animName, anim);
	mActMap[animName] = [this, animName]() { mSlide.start(animName); mIsFinished = false; };
}

