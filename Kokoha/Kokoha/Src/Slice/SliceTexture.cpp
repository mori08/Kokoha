#include "SliceTexture.h"


Kokoha::SliceTexture::SliceTexture(const String& textureName, const Size& sliceSize, const Point& pos)
	: mTextureName(textureName)
	, mSliceSize(sliceSize)
	, mTexturePos(pos)
	, mMirror(false)
{
}
