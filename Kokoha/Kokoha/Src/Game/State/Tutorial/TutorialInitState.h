#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialInitStateクラス
	チュートリアル開始の状態
	*/
	class TutorialInitState : public TutorialState
	{
	public:

		TutorialInitState();

	private:

		void update() override;

	};
}