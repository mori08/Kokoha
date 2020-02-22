#include "TutorialInitState.h"
#include "TutorialMoveState.h"
#include "../../GameManager.h"


namespace
{
	// ��Ԃ̕ύX����
	constexpr double CHANGE_STATE_SECOND = 5.0;
}


Kokoha::TutorialInitState::TutorialInitState()
	: TutorialState(U"��ԁF����\n�`���[�g���A���J�n", U"������@�̊m�F")
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
