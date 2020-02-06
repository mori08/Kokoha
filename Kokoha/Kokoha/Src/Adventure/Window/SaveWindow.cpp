#include "SaveWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Record/RecordManager.h"
#include "../../Input/InputManager.h"


namespace
{
	// ウィンドウサイズ
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
		FontAsset(U"20")(U"セーブ中").drawAt(Scene::Center());
	}
	else
	{
		FontAsset(U"20")(U"セーブできました．").drawAt(Scene::Center());
	}
}
