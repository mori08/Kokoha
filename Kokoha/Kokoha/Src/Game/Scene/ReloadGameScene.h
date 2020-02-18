#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	ReloadGameScene�N���X
	GameManager��reload�֐����Ăт܂��D
	*/
	class ReloadGameScene : public LoadScene
	{
	private:

		// ���[�h�ɐ��������Ƃ� true, �����łȂ��Ƃ� false
		bool mIsSuccess;

	public:

		ReloadGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}