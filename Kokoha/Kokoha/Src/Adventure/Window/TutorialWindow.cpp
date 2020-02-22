#include "TutorialWindow.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../Input/InputManager.h"


namespace
{
	// �E�B���h�E�̃T�C�Y
	constexpr Size WINDOW_SIZE(260, 100);

	// �e�L�X�g��\��������W
	constexpr Point DRAW_TEXT_POS(200, 200);
}


Kokoha::TutorialWindow::TutorialWindow()
	: AdventureWindow(getRectFromCenter(Scene::Center(), WINDOW_SIZE))
{

}


void Kokoha::TutorialWindow::select()
{
}


void Kokoha::TutorialWindow::update()
{
}


void Kokoha::TutorialWindow::selectedUpdate()
{
	if (InputManager::instance().decision() || InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::TutorialWindow::draw() const
{
	drawBoard();

	FontAsset(U"20")(U"WASD\nEnter\nBackspace").draw(DRAW_TEXT_POS);
	FontAsset(U"20")(U"�ړ�\n���ׂ�\n���j���[").draw(320, DRAW_TEXT_POS.y);
}
