#include "CassetteManager.h"


Kokoha::CassetteManager::CassetteManager()
{
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hI",
			1,
			CassetteEffect(0, []() {})
		)
	);
}