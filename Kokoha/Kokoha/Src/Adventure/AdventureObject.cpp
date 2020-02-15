#include "AdventureObject.h"
#include "AdventureManager.h"
#include "../MyLibrary.h"
#include "../Input/InputManager.h"
#include "../Record/RecordManager.h"

// ウィンドウ
#include "Window/InfoWindow.h"
#include "Window/ChallengeStageWindow.h"
#include "Window/AreaWindow.h"


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
	sMakeWindowFuncMap[U"TrashBox"]        = []() { openWindow(std::make_unique<InfoWindow>(U"作りかけのロボットが捨ててある.")); };
	sMakeWindowFuncMap[U"Cardboard"]       = []() { openWindow(std::make_unique<InfoWindow>(U"段ボール,\n中身は分からない.")); };
	sMakeWindowFuncMap[U"OpenedCardboard"] = []() { openWindow(std::make_unique<InfoWindow>(U"段ボール,\n中身は空だ.")); };
	sMakeWindowFuncMap[U"Shelf"]           = []() { openWindow(std::make_unique<InfoWindow>(U"大きな棚だ.\n高い所は届かない.")); };
	sMakeWindowFuncMap[U"LaboWorkbench"]   = []() { openWindow(std::make_unique<InfoWindow>(U"作業台,\n何かを作った跡がある.")); };
	sMakeWindowFuncMap[U"BookShelf"]       = []() { openWindow(std::make_unique<InfoWindow>(U"本棚,\n本はホコリをかぶっている.")); };
	sMakeWindowFuncMap[U"DeadDoctor"]      = []() { openWindow(std::make_unique<InfoWindow>(U"ゴミ箱,\nとても汚れている.\n中には何かが詰め込まれている.")); };

	// ステージに挑戦
	sMakeWindowFuncMap[U"BrokenSearcher1"]  = []() { openStageWindow(U"1-1"); };
	sMakeWindowFuncMap[U"BrokenSearcher2"]  = []() { openStageWindow(U"1-2"); };
	sMakeWindowFuncMap[U"BrokenSearcher0"]  = []() { openStageWindow(U"1-3"); };
	sMakeWindowFuncMap[U"BrokenDeveloper"]  = []() { openStageWindow(Array<String>{U"2-1", U"2-2", U"2-3"}); };
	sMakeWindowFuncMap[U"BrokenRepair0"]    = []() { openStageWindow(U"3-1"); };
	sMakeWindowFuncMap[U"BrokenRepair1"]    = []() { openStageWindow(U"3-2"); };
	sMakeWindowFuncMap[U"BrokenRepair2"]    = []() { openStageWindow(U"3-3"); };
	sMakeWindowFuncMap[U"BrokenResearcher"] = []() { openStageWindow(Array<String>{U"4-1", U"4-2", U"4-3"}); };
	sMakeWindowFuncMap[U"PC"]               = []() { openStageWindow(Array<String>{U"5-1", U"5-2", U"5-3"}); };
	sMakeWindowFuncMap[U"BrokenHelpRobot"]  = []() { openStageWindow(Array<String>{U"6-1", U"6-2", U"6-3"}); };
	sMakeWindowFuncMap[U"EntranceGate"]     = []() { openStageWindow(U"Last"); };

	// 別エリアに移動
	sMakeWindowFuncMap[U"Door[StoreRoom]"]   = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[Labolatory]"]  = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[Entrance]"]    = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[Library]"]     = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[DoctorRoom]"]  = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[GarbageDump]"] = []() { openWindow(std::make_unique<AreaWindow>()); };
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


void Kokoha::AdventureObject::openStageWindow(const String& stageName)
{
	if (RecordManager::instance().getRecord(stageName))
	{
		if (stageName == U"Last")
		{
			return;
		}

		openWindow(std::make_unique<InfoWindow>(U"このロボットには\nもう用はない"));
		return;
	}

	openWindow(std::make_unique<ChallengeStageWindow>(stageName));
}


void Kokoha::AdventureObject::openStageWindow(const Array<String>& stageNameList)
{
	for (const auto& stageName : stageNameList)
	{
		if (RecordManager::instance().getRecord(stageName)) { continue; }
		
		// クリアしていないステージがあるとき
		openWindow(std::make_unique<ChallengeStageWindow>(stageName));

		return;
	}

	if (!stageNameList.empty() && stageNameList[0] == U"5-1")
	{
		openWindow(std::make_unique<InfoWindow>(U"このパソコンには\nもう用はない"));
		return;
	}

	// 全てクリアしているとき
	openWindow(std::make_unique<InfoWindow>(U"このロボットには\nもう用はない"));
}
