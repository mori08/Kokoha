#include "InfoWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/InputManager.h"


namespace
{
	// ウィンドウのサイズの追加分
	constexpr Size OFFSET(40, 20);
}


Kokoha::InfoWindow::InfoWindow(const String& text)
	: AdventureWindow(getRectFromCenter(Scene::Center(), FontAsset(U"20")(text).region().size + OFFSET))
	, mText(text)
{
}


void Kokoha::InfoWindow::select()
{

}


void Kokoha::InfoWindow::update()
{

}


void Kokoha::InfoWindow::selectedUpdate()
{
	if (InputManager::instatnce().decision() || InputManager::instatnce().cancel())
	{
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::InfoWindow::draw() const
{
	drawBoard();
	FontAsset(U"20")(mText).drawAt(mWindowBoard.center());
}
