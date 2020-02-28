#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialCassetteStateクラス
	カセット変更の説明
	*/
	class TutorialCassetteState : public TutorialState
	{
	private:

		// 装備変更回数
		int32 mEquipmentChangeCount;

	public:

		TutorialCassetteState();

	private:

		void update() override;

		void draw() const override;

	};
}