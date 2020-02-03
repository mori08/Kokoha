#pragma once


#include "AdventureWindow.h"
#include <thread>


namespace Kokoha
{
	/*
	SaveWindow�N���X
	���R�[�h���Z�[�u����E�B���h�E
	*/
	class SaveWindow : public AdventureWindow
	{
	private:

		// �Z�[�u�p�X���b�h
		std::thread mSaveThread;

		// true �̂Ƃ� �Z�[�u��
		bool mIsSaving;

	public:

		SaveWindow();

	public:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}