#include "CassetteInfoWindow.h"
#include "../../Input/InputManager.h"
#include "../AdventureManager.h"
#include "../../MyLibrary.h"
#include "../../MyColor.h"


namespace
{
	// �E�B���h�E�̃T�C�Y
	constexpr Size TEXTURE_SIZE(360, 240);

	// �A�C�R���̕\�����W
	constexpr Point TEXTURE_POS(190, 150);

	// ���O�̍��W
	constexpr Point NAME_POS(290, 150);

	// �e�L�X�g��\��������W
	constexpr Point TEXT_POS(160, 180);
}


CSVData Kokoha::CassetteInfoWindow::sCSV;


Kokoha::CassetteInfoWindow::CassetteInfoWindow(const CassettePtr& cassette)
	: AdventureWindow(getRectFromCenter(Scene::Center(), TEXTURE_SIZE))
	, mCassettePtr(cassette)
{

}


void Kokoha::CassetteInfoWindow::select()
{
	
}


void Kokoha::CassetteInfoWindow::update()
{

}


void Kokoha::CassetteInfoWindow::selectedUpdate()
{
	if (InputManager::instance().decision() || InputManager::instance().cancel())
	{
		AdventureManager::instance().closeWindow();
	}
}


void Kokoha::CassetteInfoWindow::draw() const
{
	drawBoard();

	mCassettePtr->getIconTexture().drawAt(TEXTURE_POS);

	FontAsset(U"20")(mCassettePtr->NAME).drawAt(NAME_POS, MyWhite);

	String text;
	text += U"�R�X�g�@�F" + ToString(mCassettePtr->COST) + U"\n";
	text += U"�҂����ԁF" + sCSV[mCassettePtr->ID][0] + U"\n";

	FontAsset(U"20")(text).draw(TEXT_POS, MyWhite);

	FontAsset(U"20")(sCSV[mCassettePtr->ID][1]).draw(TEXT_POS + Point(10, 70));
}


void Kokoha::CassetteInfoWindow::readCSVData()
{
	sCSV.load(U"Assets/Data/CassetteInfo.csv");
}
