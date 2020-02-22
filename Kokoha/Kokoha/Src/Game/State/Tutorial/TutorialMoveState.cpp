#include "TutorialMoveState.h"
#include "TutorialCassetteState.h"
#include "../../GameManager.h"
#include "../../Object/Player/GamePlayer.h"
#include "../../../MyLibrary.h"


namespace
{
	// 目標距離
	constexpr double ACHIEVE_DISTANCE = 300;
}


Kokoha::TutorialMoveState::TutorialMoveState()
	: TutorialState(U"移動方法の確認", U"WASDキー")
	, mMoveDistance(0)
{
	const Vec2 pos = StageData::squareToPixel(Point(12, 7)); // プレイヤーの座標
	
	mPlayerPos = pos;
	GameManager::instance().addObject(std::make_unique<GamePlayer>(pos));
}


void Kokoha::TutorialMoveState::update()
{
	GameManager::instance().updateObject();

	// プレイヤー関連情報の更新
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

	// WASDキーの表示
	
}
