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

		void load() override;

		void complete() override;

	};
}