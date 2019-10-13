#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	SaveRecordScene�N���X
	���R�[�h��RECORD.txt�ɃZ�[�u����.
	*/
	class SaveRecordScene : public LoadScene
	{
	public:

		SaveRecordScene(const InitData& init);

	private:

		ErrorMessage load() override;

		SceneName complete() override;

	};
}