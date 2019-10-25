#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadGameScene�N���X
	GameManager��load�֐����Ăт܂�.
	*/
	class LoadGameScene : public LoadScene
	{
	private:

		// ���[�h�ɐ��������Ƃ� true , �����łȂ��Ƃ� false
		bool mIsSuccess;

	public:

		LoadGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}