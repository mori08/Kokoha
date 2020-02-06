#include "SaveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Record/RecordManager.h"
#include "../../Input/InputManager.h"


namespace
{
	// �E�B���h�E�T�C�Y
	constexpr Size WINDOW_SIZE(200, 50);
}


Kokoha::SaveWindow::SaveWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
{
	mIsSaving = true;

	mSaveThread = std::thread
	(
		[this]()
		{
			RecordManager::instance().save();
			mIsSaving = false;
		}
	);
}


void Kokoha::SaveWindow::select()
{
}


void Kokoha::SaveWindow::update()
{
}


void Kokoha::SaveWindow::selectedUpdate()
{
	if (mIsSaving) { return; }

	if (InputManager::instance().decision() || InputManager::instance().cancel())
	{
		mSaveThread.join();
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::SaveWindow::draw() const
{
	drawBoard();

	if (mIsSaving)
	{
		FontAsset(U"20")(U"�Z�[�u��").drawAt(Scene::Center());
	}
	else
	{
		FontAsset(U"20")(U"�Z�[�u�ł��܂����D").drawAt(Scene::Center());
	}
}
