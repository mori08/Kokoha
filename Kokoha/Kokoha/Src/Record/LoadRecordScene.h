#pragma once


#include "../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadRecordScene�N���X
	���R�[�h��RECORD.txt���烍�[�h����.
	*/
	class LoadRecordScene : public LoadScene
	{
	public:

		LoadRecordScene(const InitData& init);

	private:

		void load() override;

		void complete() override;

	};
}