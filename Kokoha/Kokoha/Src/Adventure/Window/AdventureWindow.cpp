#include "AdventureWindow.h"
#include "../../MyColor.h"


namespace
{
	// �E�B���h�E�̊p�̊ۂ݂̔��a
	constexpr int32 BOARD_R = 5;

	// �E�B���h�E�̉��̌���
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
