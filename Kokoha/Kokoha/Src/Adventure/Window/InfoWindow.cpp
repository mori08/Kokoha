#include "InfoWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/InputManager.h"


namespace
{
	constexpr Size OFFSET(40, 20);
}


Kokoha::InfoWindow::InfoWindow(const String& text)
	: AdventureWindow(getRectFromCenter(Scene::Center(), FontAsset(U"20")(text).region().size + OFFSET))
	, mText(text)
{
	select();
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
