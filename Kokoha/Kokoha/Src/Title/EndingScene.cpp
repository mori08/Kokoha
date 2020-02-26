#include "EndingScene.h"
#include "../Record/RecordManager.h"
#include "../Input/InputManager.h"


namespace
{
	constexpr Point DRAW_TEXT_POS(400, 445);
}


Kokoha::EndingScene::EndingScene(const InitData& init)
	: IScene(init)
{
	if (RecordManager::instance().getRecord(U"Kokoro"))
	{
		mEndingName = U"エンド２ [ ココロ ]";
	}
	else
	{
		RecordManager::instance().setRecord(U"Last", 0);
		mEndingName = U"エンド１ [ ロボット ]";
	}
}


void Kokoha::EndingScene::update()
{
	if (InputManager::instance().decision() || InputManager::instance().cancel())
	{
		changeScene(SceneName::SAVE_RECORD);
	}
}


void Kokoha::EndingScene::draw() const
{
	FontAsset(U"20")(mEndingName).draw(DRAW_TEXT_POS);
}
