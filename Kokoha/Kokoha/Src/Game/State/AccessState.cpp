#include "AccessState.h"
#include "PlayingState.h"
#include "../../MyColor.h"
#include "../GameManager.h"
#include "../../MyLibrary.h"


namespace
{
	// アイコンの中心座標
	constexpr Point MAIN_ROBOT_POS(140, 240);
	constexpr Point TARGET_POS(500, 240);

	// 半径
	constexpr double RADIUS = 640;
	// 円を表示する時間
	constexpr double CIRCLE_SECOND = 2;

	// 状態変更時間
	constexpr double CHANGE_STATE_SECOND = 3.0;
}


std::unordered_map<String, String> Kokoha::AccessState::sRobotIconMap;


Kokoha::AccessState::AccessState()
	: mTimeSecond(0)
	, mAlpha(1)
{
}


void Kokoha::AccessState::update()
{
	mTimeSecond += Scene::DeltaTime();
	if (mTimeSecond > CIRCLE_SECOND)
	{
		internalDividingPoint
		(
			mAlpha,
			0.0,
			0.001
		);
	}

	if (mTimeSecond > CHANGE_STATE_SECOND)
	{
		GameManager::instance().setState(std::make_unique<PlayingState>());
	}
}


void Kokoha::AccessState::draw() const
{
	TextureAsset(U"MainRobotIcon").drawAt(MAIN_ROBOT_POS, AlphaF(mAlpha));
	TextureAsset(sRobotIconMap[GameManager::instance().getName()]).drawAt(TARGET_POS, AlphaF(mAlpha));

	double radius = RADIUS * mTimeSecond / CIRCLE_SECOND;
	Circle(MAIN_ROBOT_POS, radius).drawFrame(4, ColorF(MyWhite).setA(mAlpha));

	if (RADIUS - radius < 0) { return; }
	Circle(TARGET_POS, RADIUS - radius).drawFrame(4, ColorF(MyWhite).setA(mAlpha));
}


void Kokoha::AccessState::setRobotIcon()
{
	sRobotIconMap[U"1-1"] = U"Searcher1Icon";
	sRobotIconMap[U"1-2"] = U"Searcher2Icon";
	sRobotIconMap[U"1-3"] = U"Searcher0Icon";

	sRobotIconMap[U"2-1"] = U"DeveloperIcon";
	sRobotIconMap[U"2-2"] = U"DeveloperIcon";
	sRobotIconMap[U"2-3"] = U"DeveloperIcon";

	sRobotIconMap[U"3-1"] = U"Repair0Icon";
	sRobotIconMap[U"3-2"] = U"Repair1Icon";
	sRobotIconMap[U"3-3"] = U"Repair2Icon";

	sRobotIconMap[U"4-1"] = U"ResearcherIcon";
	sRobotIconMap[U"4-2"] = U"ResearcherIcon";
	sRobotIconMap[U"4-3"] = U"ResearcherIcon";

	sRobotIconMap[U"5-1"] = U"DoctorIcon";
	sRobotIconMap[U"5-2"] = U"DoctorIcon";
	sRobotIconMap[U"5-3"] = U"DoctorIcon";

	sRobotIconMap[U"6-1"] = U"HelpRobotIcon";
	sRobotIconMap[U"6-2"] = U"HelpRobotIcon";
	sRobotIconMap[U"6-3"] = U"HelpRobotIcon";

	sRobotIconMap[U"Last"]   = U"EntranceGateIcon";
	sRobotIconMap[U"Kokoro"] = U"BoxRobotIcon";
}
