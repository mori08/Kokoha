#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadAdventureScene�N���X
	AdventureManager��load�֐����Ăт܂�.
	*/
	class LoadAdventureScene : public LoadScene
	{
	private:

		// ���[�h�ɐ��������Ƃ� true , �����łȂ��Ƃ� false
		bool mIsSuccess;

	public:

		LoadAdventureScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}