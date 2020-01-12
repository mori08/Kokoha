#include "CassetteManager.h"


Kokoha::CassetteManager::CassetteManager()
	: mEquipment( { Equipment(Cassette::EQUIPMENT_A_STATE),Equipment(Cassette::EQUIPMENT_B_STATE) })
{
	
	// スピードI
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードI",
			1,
			Cassette::makeSpeedEffect(1.1, { 0,Inf<double> })
		)
	);
	
	// スピードII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードII",
			2,
			Cassette::makeSpeedEffect(1.3, { 0,Inf<double> })
		)
	);

	// スピードIII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"スピードIII",
			3,
			Cassette::makeSpeedEffect(1.5, { 0,Inf<double> })
		)
	);

	// アクセルI
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルI",
			1,
			Cassette::makeSpeedEffect(2.0, { 3.0,4.0 })
		)
	);

	// アクセルII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルII",
			2,
			Cassette::makeSpeedEffect(2.0, { 2.0,5.0 })
		)
	);

	// アクセルIII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"アクセルIII",
			3,
			Cassette::makeSpeedEffect(2.0, { 1.0,6.0 })
		)
	);

	// ダッシュ
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"ダッシュ",
			2,
			Cassette::makeSpeedEffect(1.5, { 3.0,Inf<double> })
		)
	);

	// ダッシュ
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"ダッシュ",
			2,
			Cassette::makeSpeedEffect(1.5, { 3.0,Inf<double> })
		)
	);
}