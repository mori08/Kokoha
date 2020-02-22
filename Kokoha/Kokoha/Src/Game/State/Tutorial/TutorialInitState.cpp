#include "TutorialInitState.h"
#include "TutorialMoveState.h"
#include "../../GameManager.h"


namespace
{
	// 状態の変更時間
	constexpr double CHANGE_STATE_SECOND = 5.0;
}


Kokoha::TutorialInitState::TutorialInitState()
	: TutorialState(U"状態：正常\nチュートリアル開始", U"操作方法の確認")
{
}


void Kokoha::TutorialInitState::update()
{
	updateAchieveRate(mTimeSecond / CHANGE_STATE_SECOND);

	if (mTimeSecond > CHANGE_STATE_SECOND)
	{
		GameManager::instance().setState(std::make_unique<TutorialMoveState>());
		return;
	}

	TutorialState::update();
}
