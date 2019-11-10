#include "CassetteManager.h"


Kokoha::CassetteManager::CassetteManager()
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
}