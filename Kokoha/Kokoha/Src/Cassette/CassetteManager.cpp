#include "CassetteManager.h"
#include "../Game/GameManager.h"

#include "../Game/Object/Light/PlayerLight.h"
#include "../Game/Object/Light/RandomLight.h"
#include "../Game/Object/Light/GoalLight.h"


Kokoha::CassetteManager::CassetteManager()
	: mEquipment( { Equipment(Cassette::EQUIPMENT_A_STATE),Equipment(Cassette::EQUIPMENT_B_STATE) })
{
	
	// �X�s�[�h //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hI",
			1,
			Cassette::makeSpeedEffect(1.2, { 0,Inf<double> })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hII",
			2,
			Cassette::makeSpeedEffect(1.4, { 0,Inf<double> })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�X�s�[�hIII",
			3,
			Cassette::makeSpeedEffect(1.8, { 0,Inf<double> })
		)
	);

	// �A�N�Z�� //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��I",
			1,
			Cassette::makeSpeedEffect(2.0, { 3.0,5.0 })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��II",
			2,
			Cassette::makeSpeedEffect(2.0, { 2.0,6.0 })
		)
	);
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�A�N�Z��III",
			3,
			Cassette::makeSpeedEffect(2.0, { 1.0,7.0 })
		)
	);

	// �v���C���[ //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�v���C���[I",
			1,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(2.0)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�v���C���[II",
			2,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(4.0)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�v���C���[III",
			3,
			CassetteEffect(0.5, []() { GameManager::instance().addObject(std::make_unique<PlayerLight>(6.0)); })
		)
	);

	// �G�l�~�[ //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�G�l�~�[I",
			1,
			CassetteEffect(0, []() {})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�G�l�~�[II",
			2,
			CassetteEffect(0, []() {})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�G�l�~�[III",
			3,
			CassetteEffect(0, []() {})
		)
	);

	// �����_�� //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�����_��I",
			1,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(1.5)); }})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�����_��II",
			2,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(2.5)); }})
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�����_��III",
			3,
			CassetteEffect(0.5, []() {for (int32 i = 0; i < 3; ++i) { GameManager::instance().addObject(std::make_unique<RandomLight>(3.5)); }})
		)
	);

	// �S�[�� //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�S�[��I",
			1,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(1.5, 5.0, false)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�S�[��II",
			2,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(1.5, 5.0, true)); })
		)
	);
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�S�[��III",
			3,
			CassetteEffect(2.5, []() { GameManager::instance().addObject(std::make_unique<GoalLight>(3.0, 10.0, true)); })
		)
	);

	// �_�b�V�� //
	mCassetteList.emplace_back(
		std::make_shared<Cassette>
		(
			U"�_�b�V��",
			2,
			Cassette::makeSpeedEffect(1.6, { 3.0,Inf<double> })
		)
	);

	// �t���b�V�� //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�t���b�V��",
			2,
			CassetteEffect(0, []() {})
		)
	);

	// �R�R�� //
	mCassetteList.emplace_back
	(
		std::make_shared<Cassette>
		(
			U"�R�R��",
			3,
			CassetteEffect(0, []() {})
		)
	);

	// �f�o�b�O�p�ɃJ�Z�b�g������������
	for (auto& cassette : mCassetteList)
	{
		cassette->setState(Cassette::POSSESS_STATE);
	}
}