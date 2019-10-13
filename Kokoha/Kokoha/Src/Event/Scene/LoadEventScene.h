#pragma once


#include "../../Load/LoadScene.h"


namespace Kokoha
{
	/*
	LoadEventScene�N���X
	�C�x���g���L�q���ꂽCSV�t�@�C����ǂݍ��݂܂�.
	*/
	class LoadEventScene : public LoadScene
	{
	private:

		// ���[�h�ɐ��������Ƃ� true , �����łȂ��Ƃ� false
		bool mIsScuccess;

	public:

		LoadEventScene(const InitData& init);

	private:

		void load() override;

		void complete() override;

	};
}