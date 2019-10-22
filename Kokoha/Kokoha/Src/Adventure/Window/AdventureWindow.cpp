#include "AdventureWindow.h"
#include "../../MyColor.h"


namespace
{
	// ウィンドウの角の丸みの半径
	constexpr int32 BOARD_R = 5;

	// ウィンドウの縁の厚さ
	constexpr double BOARD_THICK = 2.0;
}


Kokoha::AdventureWindow::AdventureWindow(const Rect& region)
	: mWindowBoard(region, BOARD_R)
{
}


void Kokoha::AdventureWindow::drawBoard() const
{
	mWindowBoard.draw(MyBlack);
	mWindowBoard.drawFrame(BOARD_THICK, MyWhite);
}
