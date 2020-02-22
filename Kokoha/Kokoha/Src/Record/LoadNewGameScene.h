#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadNewGameScene�N���X
	���R�[�h�����������Ă͂��߂���n�܂�
	*/
	class LoadNewGameScene : public LoadScene
	{
	public:

		LoadNewGameScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}