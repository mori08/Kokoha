#include "SliceTexture.h"
#include "../MyLibrary.h"


Kokoha::SliceTexture::SliceTexture(const String& textureName, const Size& sliceSize, const Point& pos)
	: mTextureName(textureName)
	, mSliceSize(sliceSize)
	, mMirror(false)
	, mChangeSpan(0,0)
	, mAnimationName(U"Default")
{
	setAnimation(mAnimationName, 0, Array<Point>{ pos }, false);
}


void Kokoha::SliceTexture::setTextureName(const String& textureName, const Size& sliceSize)
{
	mTextureName = textureName;
	mSliceSize   = sliceSize;
}


bool Kokoha::SliceTexture::changeTexture()
{
	if (!mChangeSpan.update()) { return false; }

	if (!mAnimationMap[mAnimationName].IS_LOOP) { return true; }

	mChangeSpan.restart();

	return false;
}


void Kokoha::SliceTexture::start(const String name)
{
	if (!mAnimationMap.count(name))
	{
		printDebug(U"[SliceTexture::start]");
		printDebug(U"“o˜^‚³‚ê‚Ä‚¢‚È‚¢ƒAƒjƒ[ƒVƒ‡ƒ“‚Å‚·");
		printDebug(U"mTextureName > " + mTextureName);
		printDebug(U"name > " + name);
		return;
	}

	mAnimationName = name;
	mChangeSpan    = Linearly<double>(mAnimationMap[name].TIME, (double)mAnimationMap[name].POS_LIST.size());
}


TextureRegion Kokoha::SliceTexture::getTexture() const
{
	const auto& POS_LIST = mAnimationMap.find(mAnimationName)->second.POS_LIST;

	Point texturePos = POS_LIST[Min(POS_LIST.size() - 1, (size_t)mChangeSpan.getValue())];

	auto texture = TextureAsset(mTextureName)(texturePos * mSliceSize, mSliceSize);
	
	if (mMirror) { texture = texture.mirrored(); }

	return texture;
}
