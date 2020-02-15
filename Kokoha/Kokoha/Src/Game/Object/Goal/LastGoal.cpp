#include "LastGoal.h"
#include "../Enemy/DefenceRandomEnemy.h"
#include "../Enemy/DefenceClingEnemy.h"
#include "../Enemy/DefenceChaseEnemy.h"
#include "../Enemy/DefenceGuardEnemy.h"
#include "../../GameManager.h"
#include "../../../MyLibrary.h"


namespace 
{
	// �ړ����x
	constexpr double CHASE_SPEED = 0.1;

	// �ړ����x
	constexpr double RUNAWAY_SPEED = 0.5;

	// ���̐�
	constexpr int32 KEY_NUM = 6;

	// ��]�̔��a
	constexpr double RADIUS = 48.0;

	// �p���x
	constexpr double ANGLE_SPEED = 1.0;
}


Kokoha::LastGoal::LastGoal(const Vec2& pos)
	: GameGoal(pos, CHASE_SPEED)
	, mIsOpened(false)
{
	mSlide.start(U"lock");

	mDefenceEnemyList.emplace_back(std::make_unique<DefenceRandomEnemy>(pos));
	mDefenceEnemyList.emplace_back(std::make_unique<DefenceRandomEnemy>(pos));
	mDefenceEnemyList.emplace_back(std::make_unique<DefenceClingEnemy> (pos));
	mDefenceEnemyList.emplace_back(std::make_unique<DefenceClingEnemy> (pos));
	mDefenceEnemyList.emplace_back(std::make_unique<DefenceChaseEnemy> (pos));
	mDefenceEnemyList.emplace_back(std::make_unique<DefenceGuardEnemy> (pos));

	mKeyList.emplace_back(pos);
}


void Kokoha::LastGoal::update()
{
	mSlide.changeTexture();

	// �G�̍X�V
	for (int32 i = 0; i < KEY_NUM; ++i)
	{
		if (i < mKeyList.size() + mKeyList.rbegin()->isChecked() - 1)
		{
			mDefenceEnemyList[i]->offDefenceMode();
		}
		else
		{
			double angle
				= ANGLE_SPEED * Scene::Time()
				+ Math::TwoPi * i / (KEY_NUM - (int32)mKeyList.size() + 1);

			mDefenceEnemyList[i]->setToPos(mBody.center + RADIUS * angleToVec(angle));
		}

		mDefenceEnemyList[i]->update();
	}

	if (mIsOpened)
	{
		walkToGoal(RUNAWAY_SPEED, GameManager::instance().getStageData().getRunAwayPixel(mBody.center));
		return;
	}

	// ���̍X�V
	mKeyList.rbegin()->update();
	// �v���C���[�Ɍ������ꂽ�Ƃ�
	if (mKeyList.rbegin()->isChecked())
	{
		// ����S�Ď��ꂽ��S�[�����J����
		if ((int32)mKeyList.size() == KEY_NUM)
		{
			mIsOpened = true;
			mSlide.start(U"unlock");
		}
		else
		{
			// ���̒ǉ�
			mKeyList.emplace_back(mBody.center);
		}
	}

	walkToGoal(CHASE_SPEED, GameManager::instance().getPlayerPos());
}


void Kokoha::LastGoal::draw() const
{
	GameGoal::draw();

	for (const auto& enemy : mDefenceEnemyList) { enemy->draw(); }

	for (const auto& key : mKeyList) { key.draw(); }
}


void Kokoha::LastGoal::drawLight() const
{
	GameGoal::drawLight();

	for (const auto& enemy : mDefenceEnemyList) { enemy->drawLight(); }
}


void Kokoha::LastGoal::checkAnother(const GameObject& another)
{
	for (auto& enemy : mDefenceEnemyList) 
	{
		enemy->checkAnother(*this);
		enemy->checkAnother(another); 
	}

	for (auto& key : mKeyList) { key.checkAnother(another); }

	if (mIsOpened)
	{
		GameGoal::checkAnother(another);
	}
}
