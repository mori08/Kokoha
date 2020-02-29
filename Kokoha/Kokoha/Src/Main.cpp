# define SIV3D_CONCURRENT

#include "MyLibrary.h"
#include "MyColor.h"
#include "Input/InputManager.h"

// シーン
#include "Title/TitleScene.h"
#include "Title/EndingScene.h"
#include "Record/SaveRecordScene.h"
#include "Record/LoadRecordScene.h"
#include "Record/LoadNewGameScene.h"
#include "Event/Scene/LoadEventScene.h"
#include "Event/Scene/EventScene.h"
#include "Adventure/Scene/LoadAdventureScene.h"
#include "Adventure/Scene/AdventureScene.h"
#include "Game/Scene/LoadGameScene.h"
#include "Game/Scene/ReloadGameScene.h"
#include "Game/Scene/GameScene.h"
#include "Load/TestLoadScene.h"


namespace
{
	// 画面サイズ
	constexpr Size WINDOW_SIZE(640, 480);
}


void Main()
{
	// ウィンドウサイズの設定
	Window::Resize(WINDOW_SIZE);
	Window::SetTitle(U"558");

	// 描画設定
	Scene::SetBackground(Kokoha::MyBlack);
	Scene::Resize(WINDOW_SIZE);

	// アセット管理
	Kokoha::outputResource(U"Assets/");
	Kokoha::registerAsset(U"Assets/");
	FontAsset::Register(U"10", 10, Typeface::Medium);
	FontAsset::Register(U"15", 15, Typeface::Medium);
	FontAsset::Register(U"20", 20, Typeface::Medium);
	FontAsset::Register(U"30", 30, Typeface::Medium);
	FontAsset::Register(U"40", 40, Typeface::Medium);

	// シーンの設定
	MyApp sceneManager;
	sceneManager.add<Kokoha::TitleScene>        (SceneName::TITLE);
	sceneManager.add<Kokoha::EndingScene>       (SceneName::ENDING);
	sceneManager.add<Kokoha::SaveRecordScene>   (SceneName::SAVE_RECORD);
	sceneManager.add<Kokoha::LoadRecordScene>   (SceneName::LOAD_RECORD);
	sceneManager.add<Kokoha::LoadNewGameScene>  (SceneName::LOAD_NEWGAME);
	sceneManager.add<Kokoha::LoadEventScene>    (SceneName::LOAD_EVENT);
	sceneManager.add<Kokoha::EventScene>        (SceneName::EVENT);
	sceneManager.add<Kokoha::LoadAdventureScene>(SceneName::LOAD_ADVENTURE);
	sceneManager.add<Kokoha::AdventureScene>    (SceneName::ADVENTURE);
	sceneManager.add<Kokoha::LoadGameScene>     (SceneName::LOAD_GAME);
	sceneManager.add<Kokoha::ReloadGameScene>   (SceneName::RELOAD_GAME);
	sceneManager.add<Kokoha::GameScene>         (SceneName::GAME);
	sceneManager.add<Kokoha::TestLoadScene>     (SceneName::TEST_LOAD);
	
	while (System::Update())
	{
		ClearPrint();

		sceneManager.update();

		Kokoha::InputManager::instance().changeInputState();
		
		Kokoha::showFps();
	}
}
