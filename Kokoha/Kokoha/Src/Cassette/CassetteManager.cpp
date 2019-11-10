#include "CassetteManager.h"


Kokoha::CassetteManager::CassetteManager()
{
	// �X�s�[�hI
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hI",
			1,
			Cassette::makeSpeedEffect(1.1, { 0,Inf<double> })
		)
	);

	// �X�s�[�hII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hII",
			2,
			Cassette::makeSpeedEffect(1.3, { 0,Inf<double> })
		)
	);

	// �X�s�[�hIII
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hIII",
			3,
			Cassette::makeSpeedEffect(1.5, { 0,Inf<double> })
		)
	);
}