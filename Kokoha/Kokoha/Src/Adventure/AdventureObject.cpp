#include "AdventureObject.h"
#include "AdventureManager.h"
#include "../MyLibrary.h"
#include "../Input/InputManager.h"

#include "Window/InfoWindow.h"


namespace 
{
	// プレイヤーと交差して "いる" ときの不透明度
	constexpr double INTERSECTS_ALPHA = 0.5;
	// プレイヤーと交差して "いない" ときの不透明度
	constexpr double NON_INTERSECTS_ALPHA = 1.0;
	// 不透明度の変化量を示す内分比
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
	// テキストの表示
	sMakeWindowFuncMap[U"DoctorWorkbench"] = []() { openWindow(std::make_unique<InfoWindow>(U"作業台,\n散らかってる.")); };
	sMakeWindowFuncMap[U"TrashBox0"]       = []() { openWindow(std::make_unique<InfoWindow>(U"何かが捨ててある.")); };
	sMakeWindowFuncMap[U"Cardboard"]       = []() { openWindow(std::make_unique<InfoWindow>(U"段ボール,\n中身は分からない.")); };
	sMakeWindowFuncMap[U"OpenedCardboard"] = []() { openWindow(std::make_unique<InfoWindow>(U"段ボール,\n中身は空だ.")); };
	
	// ステージに挑戦
	sMakeWindowFuncMap[U"BrokenSearcher1"] = []() { openWindow(std::make_unique<InfoWindow>(U"テスト中")); };

	// 別エリアに移動
	sMakeWindowFuncMap[U"Door[StoreRoom]"] = []() { openWindow(std::make_unique<InfoWindow>(U"エリア移動")); };
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
