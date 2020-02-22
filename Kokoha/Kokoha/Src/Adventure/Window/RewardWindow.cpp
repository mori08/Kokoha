#include "RewardWindow.h"
#include "../../Record/RecordManager.h"
#include "../../Cassette/CassetteManager.h"
#include "../../Input/InputManager.h"
#include "../../Adventure/AdventureManager.h"
#include "../../MyLibrary.h"


namespace
{
	using AreaFlag = Optional<String>;

	// ウィンドウサイズ
	constexpr Size WINDOW_SIZE(300, 140);

	// テキストを描画する位置
	constexpr Point DRAW_TEXT_POS(180, 180);
}


std::unordered_map<String, Kokoha::RewardWindow::Reward> Kokoha::RewardWindow::sRewardMap;


Kokoha::RewardWindow::RewardWindow(const String& stageName)
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
{
	if (!sRewardMap.count(stageName)) { return; }

	// エリア
	if (sRewardMap[stageName].AREA_FLAG_FUNC())
	{
		mTextList.emplace_back
		(
			U"新エリア[ " + sRewardMap[stageName].AREA_FLAG_FUNC().value() + U" ]の追加"
		);
	}

	// カセット
	if (sRewardMap[stageName].CASSETTE_ID)
	{
		int32 cassetteId = sRewardMap[stageName].CASSETTE_ID.value();

		if (CassetteManager::instance().getCassetteList()[cassetteId]->getState() != Cassette::NO_POSSESS_STATE)
		{
			return;
		}

		CassetteManager::instance().getCassetteList()[cassetteId]->setState(Cassette::POSSESS_STATE);

		mTextList.emplace_back
		(
			U"カセット[ " + CassetteManager::instance().getCassetteList()[cassetteId]->NAME + U" ]の獲得"
		);

		int32 count = RecordManager::instance().getRecord(U"CassetteCount");
		RecordManager::instance().setRecord(U"CassetteCount", ++count);
		if (count % 3 == 0)
		{
			mTextList.emplace_back
			(
				U"装備のコスト上限が増加"
			);
		}
	}
}


void Kokoha::RewardWindow::setRewardMap()
{
	// 1-
	sRewardMap.try_emplace
	(
		U"1-1",
		std::move(Reward(12, []() { return AreaFlag(U"実験室"); }))
	);
	sRewardMap.try_emplace
	(
		U"1-2",
		std::move(Reward(13, []()
			{
				if (!RecordManager::instance().getRecord(U"3-2")) { return AreaFlag(none); }
				return AreaFlag(U"ゴミ捨て場");
			}
		))
	);
	sRewardMap.try_emplace
	(
		U"1-3",
		std::move(Reward(14, []() { return AreaFlag(none); }))
	);

	// 2-
	sRewardMap.try_emplace
	(
		U"2-1",
		std::move(Reward(7, []() { return AreaFlag(U"玄関"); }))
	);
	sRewardMap.try_emplace
	(
		U"2-2",
		std::move(Reward(8, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"2-3",
		std::move(Reward(19, []() { return AreaFlag(none); }))
	);

	// 3-
	sRewardMap.try_emplace
	(
		U"3-1",
		std::move(Reward(9, []() { return AreaFlag(U"資料室"); }))
	);
	sRewardMap.try_emplace
	(
		U"3-2",
		std::move(Reward(10, []()
			{
				if (RecordManager::instance().getRecord(U"1-2")) { return AreaFlag(none); }
				return AreaFlag(U"ゴミ捨て場");
			}
		))
	);
	sRewardMap.try_emplace
	(
		U"3-3",
		std::move(Reward(11, []() { return AreaFlag(U"空き部屋"); }))
	);

	// 4-
	sRewardMap.try_emplace
	(
		U"4-1",
		std::move(Reward(15, []() { return AreaFlag(U"ハカセの部屋"); }))
	);
	sRewardMap.try_emplace
	(
		U"4-2",
		std::move(Reward(16, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"4-3",
		std::move(Reward(17, []() { return AreaFlag(none); }))
	);

	// 5-
	sRewardMap.try_emplace
	(
		U"5-1",
		std::move(Reward(1, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"5-2",
		std::move(Reward(2, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"5-3",
		std::move(Reward(18, []() { return AreaFlag(none); }))
	);

	// 6-
	sRewardMap.try_emplace
	(
		U"6-1",
		std::move(Reward(3, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"6-2",
		std::move(Reward(4, []() { return AreaFlag(none); }))
	);
	sRewardMap.try_emplace
	(
		U"6-3",
		std::move(Reward(5, []() { return AreaFlag(none); }))
	);

	// ハコガタ
	sRewardMap.try_emplace
	(
		U"Kokoro",
		std::move(Reward(20, []() {return AreaFlag(none); }))
	);
}


void Kokoha::RewardWindow::select()
{
}


void Kokoha::RewardWindow::update()
{
}


void Kokoha::RewardWindow::selectedUpdate()
{
	if (mTextList.empty() || InputManager::instance().decision() || InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::RewardWindow::draw() const
{
	if (mTextList.empty()) { return; }

	drawBoard();

	Point pos = DRAW_TEXT_POS;

	FontAsset(U"20")(U"クリア報酬").draw(pos);
	pos.y += FontAsset(U"20").height();
	pos.x += FontAsset(U"20")(U" ").region().w;

	for (const auto& text : mTextList)
	{
		FontAsset(U"20")(text).draw(pos);
		pos.y += FontAsset(U"20").height();
	}
}
