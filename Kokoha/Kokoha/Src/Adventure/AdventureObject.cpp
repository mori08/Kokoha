#include "AdventureObject.h"
#include "AdventureManager.h"
#include "../MyLibrary.h"
#include "../Input/InputManager.h"

#include "Window/InfoWindow.h"


namespace 
{
	// �v���C���[�ƌ������� "����" �Ƃ��̕s�����x
	constexpr double INTERSECTS_ALPHA = 0.5;
	// �v���C���[�ƌ������� "���Ȃ�" �Ƃ��̕s�����x
	constexpr double NON_INTERSECTS_ALPHA = 1.0;
	// �s�����x�̕ω��ʂ�����������
	constexpr double ALPHA_RATE = 0.4;
}


std::unordered_map<String, std::function<void()>> Kokoha::AdventureObject::sMakeWindowFuncMap;


Kokoha::AdventureObject::AdventureObject(const Point& pos, const String& textureName, bool pass)
	: mRegion(pos,TextureAsset(textureName).size())
	, mTextureName(textureName)
	, mAlpha(NON_INTERSECTS_ALPHA)
	, mIsPassing(pass)
	, mOnClick([](){})
{
	if (sMakeWindowFuncMap.count(mTextureName))
	{
		mOnClick = sMakeWindowFuncMap[mTextureName];
	}
}


void Kokoha::AdventureObject::registerWindow()
{
	sMakeWindowFuncMap[U"DoctorWorkbench"] = []() { openWindow(std::make_unique<InfoWindow>(U"��Ƒ�,\n�U�炩���Ă�.")); };
	sMakeWindowFuncMap[U"TrashBox0"]       = []() { openWindow(std::make_unique<InfoWindow>(U"�������̂ĂĂ���.")); };
	sMakeWindowFuncMap[U"Cardboard"]       = []() { openWindow(std::make_unique<InfoWindow>(U"�i�{�[��,\n���g�͕�����Ȃ�.")); };
}


void Kokoha::AdventureObject::update(const Rect& playerRegion)
{
	if (!mIsPassing) { return; }

	double goalAlpha = NON_INTERSECTS_ALPHA;

	if (mRegion.intersects(playerRegion))
	{
		goalAlpha = INTERSECTS_ALPHA;
	}

	internalDividingPoint(mAlpha, goalAlpha, ALPHA_RATE);
}


void Kokoha::AdventureObject::draw(const Point& cameraPoint) const
{
	TextureAsset(mTextureName).draw(mRegion.pos - cameraPoint, AlphaF(mAlpha));
}


void Kokoha::AdventureObject::openWindow(WindowPtr&& windowPtr)
{
	AdventureManager::instance().openWindow(std::move(windowPtr));
}
