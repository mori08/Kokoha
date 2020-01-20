#include "CassetteManager.h"
#include "../Game/GameManager.h"

#include "../Game/Object/Light/PlayerLight.h"
#include "../Game/Object/Light/RandomLight.h"
#include "../Game/Object/Light/GoalLight.h"


Kokoha::CassetteManager::CassetteManager()
	: mEquipment( { Equipment(Cassette::EQUIPMENT_A_STATE),Equipment(Cassette::EQUIPMENT_B_STATE) })
{
	
	// スピード //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードI",
			1,
			Cassette::makeSpeedEffect(1.2, { 0,Inf<double> })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードII",
			2,
			Cassette::makeSpeedEffect(1.4, { 0,Inf<double> })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードIII",
			3,
			Cassette::makeSpeedEffect(1.8, { 0,Inf<double> })
		)
	);

	// アクセル //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルI",
			1,
			Cassette::makeSpeedEffect(2.0, { 3.0,5.0 })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルII",
			2,
			Cassette::makeSpeedEffect(2.0, { 2.0,6.0 })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルIII",
			3,
			Cassette::makeSpeedEffect(2.0, { 1.0,7.0 })
		)
	);

	// プレイヤー //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"プレイヤーI",
			1,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(2.0)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"プレイヤーII",
			2,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(4.0)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"プレイヤーIII",
			3,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(6.0)); })
		)
	);

	// エネミー //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"エネミーI",
			1,
			CassetteEffect(0, []() {})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"エネミーII",
			2,
			CassetteEffect(0, []() {})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"エネミーIII",
			3,
			CassetteEffect(0, []() {})
		)
	);

	// ランダム //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ランダムI",
			1,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(1.5)); }})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ランダムII",
			2,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(2.5)); }})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ランダムIII",
			3,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(3.5)); }})
		)
	);

	// ゴール //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ゴールI",
			1,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(1.5, 5.0, false)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ゴールII",
			2,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(1.5, 5.0, true)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ゴールIII",
			3,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(3.0, 10.0, true)); })
		)
	);

	// ダッシュ //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"ダッシュ",
			2,
			Cassette::makeSpeedEffect(1.6, { 3.0,Inf<double> })
		)
	);

	// フラッシュ //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"フラッシュ",
			2,
			CassetteEffect(0, []() {})
		)
	);

	// ココロ //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"ココロ",
			3,
			CassetteEffect(0, []() {})
		)
	);

	// デバッグ用にカセットを所持させる
	for (auto& cassette : mCassetteList)
	{
		cassette->setState(Cassette::POSSESS_STATE);
	}
}