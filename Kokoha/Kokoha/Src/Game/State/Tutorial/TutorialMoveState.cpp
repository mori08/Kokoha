#include "TutorialMoveState.h"
#include "TutorialCassetteState.h"
#include "../../GameManager.h"
#include "../../Object/Player/GamePlayer.h"
#include "../../../MyLibrary.h"


namespace
{
	// �ڕW����
	constexpr double ACHIEVE_DISTANCE = 300;
}


Kokoha::TutorialMoveState::TutorialMoveState()
	: TutorialState(U"�ړ����@�̊m�F", U"WASD�L�[")
	, mMoveDistance(0)
{
	const Vec2 pos = StageData::squareToPixel(Point(12, 7)); // �v���C���[�̍��W
	
	mPlayerPos = pos;
	GameManager::instance().addObject(std::make_unique<GamePlayer>(pos));
}


void Kokoha::TutorialMoveState::update()
{
	GameManager::instance().updateObject();

	// �v���C���[�֘A���̍X�V
	Vec2 nextPlayerPos = GameManager::instance().getPlayerPos();
	mMoveDistance     += mPlayerPos.distanceFrom(nextPlayerPos);
	mPlayerPos         = nextPlayerPos;

	updateAchieveRate(mMoveDistance / ACHIEVE_DISTANCE);
	
	if (mMoveDistance > ACHIEVE_DISTANCE)
	{
		GameManager::instance().setState(std::make_unique<TutorialCassetteState>());
	}

	TutorialState::update();
}


void Kokoha::TutorialMoveState::draw() const
{
	TutorialState::draw();

	// WASD�L�[�̕\��
	
}
