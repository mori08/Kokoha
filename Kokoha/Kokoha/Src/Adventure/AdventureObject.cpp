#include "AdventureObject.h"
#include "../MyLibrary.h"
#include "../Input/InputManager.h"


namespace 
{
	// プレイヤーと交差して "いる" ときの不透明度
	constexpr double INTERSECTS_ALPHA = 0.5;
	// プレイヤーと交差して "いない" ときの不透明度
	constexpr double NON_INTERSECTS_ALPHA = 1.0;
	// 不透明度の変化量を示す内分比
	constexpr double ALPHA_RATE = 0.4;
}


Kokoha::AdventureObject::AdventureObject(const Point& pos, const String& textureName, bool pass)
	: mRegion(pos,TextureAsset(textureName).size())
	, mTextureName(textureName)
	, mAlpha(NON_INTERSECTS_ALPHA)
	, mIsPassing(pass)
{
}


void Kokoha::AdventureObject::update(const Rect& playerRegion)
{
	if (!mIsPassing) { return; }

	double goalAlpha = NON_INTERSECTS_ALPHA;

	if (mRegion.intersects(playerRegion))
	{
		goalAlpha = INTERSECTS_ALPHA;

		if (InputManager::instatnce().decision())
		{
			mOnClick();
		}
	}

	internalDividingPoint(mAlpha, goalAlpha, ALPHA_RATE);
}


void Kokoha::AdventureObject::draw(const Point& cameraPoint) const
{
	TextureAsset(mTextureName).draw(mRegion.pos - cameraPoint, AlphaF(mAlpha));
}
