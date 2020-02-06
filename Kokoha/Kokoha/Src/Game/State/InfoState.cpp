#include "InfoState.h"
#include "../GameManager.h"
#include "../../MyColor.h"
#include "../../MyLibrary.h"
#include "../../Input/InputManager.h"
#include "../../Record/RecordManager.h"
#include "../../Cassette/CassetteManager.h"


namespace
{
	// テキストの初期描画位置
	constexpr double INIT_DRAW_TEXT_POS = -200.0;

	// テキストの移動の比
	constexpr double POS_MOVE_RATE = 1e-4;

	// シーン遷移する時間
	constexpr double CHANGE_SCENE_TIME   = 3.0;
	constexpr double CHANGE_SCENE_TIME_2 = 8.0;
}


std::unordered_map<String, Kokoha::InfoState::Info> Kokoha::InfoState::sInfoMap;


Kokoha::InfoState::InfoState()
	: mTimeSecond(0)
	, mDrawTextPosX(INIT_DRAW_TEXT_POS)
	, mAlpha(0)
{
	// クリアしたステージ名
	String stageName = GameManager::instance().getName();

	if (!sInfoMap.count(stageName)) { return; }

	if (sInfoMap[stageName].CASSETTE_ID)
	{
		int32 cassetteId = sInfoMap[stageName].CASSETTE_ID.value();

		CassetteManager::instance().getCassetteList()[cassetteId]->setState(Cassette::POSSESS_STATE);

		mTextList.emplace_back
		(
			U"カセット[ " + CassetteManager::instance().getCassetteList()[cassetteId]->NAME + U" ] 獲得"
		);
	}

	if (sInfoMap[stageName].AREA_FLAG_FUNC())
	{
		mTextList.emplace_back
		(
			U"エリア[ " + sInfoMap[stageName].AREA_FLAG_FUNC().value() + U" ] 追加"
		);
	}
}


void Kokoha::InfoState::setInfoMap()
{
	// 1-
	sInfoMap.try_emplace
	(
		U"1-1",
		std::move(Info(0, [](){ return AreaFlag(U"実験室"); }))
	);
	sInfoMap.try_emplace
	(
		U"1-2",
		std::move(Info(1, []()
			{
				if (!RecordManager::instance().getRecord(U"3-2")) { return AreaFlag(none); }
				return AreaFlag(U"ゴミ捨て場");
			}
		))
	);
	sInfoMap.try_emplace
	(
		U"1-3",
		std::move(Info(2, []() { return AreaFlag(none); }))
	);

	// 2-
	sInfoMap.try_emplace
	(
		U"2-1",
		std::move(Info(7, []() { return AreaFlag(U"玄関"); }))
	);
	sInfoMap.try_emplace
	(
		U"2-2",
		std::move(Info(8, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"2-3",
		std::move(Info(19, []() { return AreaFlag(none); }))
	);

	// 3-
	sInfoMap.try_emplace
	(
		U"3-1",
		std::move(Info(9, []() { return AreaFlag(U"資料室"); }))
	);
	sInfoMap.try_emplace
	(
		U"3-2",
		std::move(Info(10, []() 
			{
				if (RecordManager::instance().getRecord(U"1-2")) { return AreaFlag(none); }
				return AreaFlag(U"ゴミ捨て場");
			}
		))
	);
	sInfoMap.try_emplace
	(
		U"3-3",
		std::move(Info(11, []() { return AreaFlag(U"空き部屋"); }))
	);

	// 4-
	sInfoMap.try_emplace
	(
		U"4-1",
		std::move(Info(15, []() { return AreaFlag(U"ハカセの部屋"); }))
	);
	sInfoMap.try_emplace
	(
		U"4-2",
		std::move(Info(16, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"4-3",
		std::move(Info(17, []() { return AreaFlag(none); }))
	);

	// 5-
	sInfoMap.try_emplace
	(
		U"5-1",
		std::move(Info(1, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"5-2",
		std::move(Info(2, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"5-3",
		std::move(Info(18, []() { return AreaFlag(none); }))
	);

	// 6-
	sInfoMap.try_emplace
	(
		U"6-1",
		std::move(Info(3, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"6-2",
		std::move(Info(4, []() { return AreaFlag(none); }))
	);
	sInfoMap.try_emplace
	(
		U"6-3",
		std::move(Info(5, []() { return AreaFlag(none); }))
	);

	// ハコガタ
	sInfoMap.try_emplace
	(
		U"Kokoro",
		std::move(Info(20, []() {return AreaFlag(none); }))
	);
}


void Kokoha::InfoState::update()
{
	mTimeSecond += Scene::DeltaTime();

	internalDividingPoint
	(
		mDrawTextPosX,
		0,
		POS_MOVE_RATE
	);
}


void Kokoha::InfoState::draw() const
{
	double y = 0;
	const ColorF color = ColorF(MyWhite).setA(1.0 - mDrawTextPosX / INIT_DRAW_TEXT_POS);

	for (const auto& text : mTextList)
	{
		FontAsset(U"20")(text).draw(mDrawTextPosX, y, color);

		y += FontAsset(U"20").height();
	}
}


Optional<SceneName> Kokoha::InfoState::isChangeAbleScene() const
{
	if (mTextList.empty()) { return SceneName::ADVENTURE; }

	if (mTimeSecond < CHANGE_SCENE_TIME) { return none; }

	if (InputManager::instance().decision() || InputManager::instance().cancel())
	{
		return SceneName::ADVENTURE;
	}

	if (mTimeSecond < CHANGE_SCENE_TIME_2) { return none; }

	return SceneName::ADVENTURE;
}
