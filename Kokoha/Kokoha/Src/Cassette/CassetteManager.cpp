#include "CassetteManager.h"


Kokoha::CassetteManager::CassetteManager()
	: mEquipment( { Equipment(Cassette::EQUIPMENT_A_STATE),Equipment(Cassette::EQUIPMENT_B_STATE) })
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

	// �A�N�Z��I
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��I",
			1,
			Cassette::makeSpeedEffect(2.0, { 3.0,4.0 })
		)
	);

	// �A�N�Z��II
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��II",
			2,
			Cassette::makeSpeedEffect(2.0, { 2.0,5.0 })
		)
	);

	// �A�N�Z��III
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��III",
			3,
			Cassette::makeSpeedEffect(2.0, { 1.0,6.0 })
		)
	);

	// �_�b�V��
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�_�b�V��",
			2,
			Cassette::makeSpeedEffect(1.5, { 3.0,Inf<double> })
		)
	);

	// �_�b�V��
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�_�b�V��",
			2,
			Cassette::makeSpeedEffect(1.5, { 3.0,Inf<double> })
		)
	);
}