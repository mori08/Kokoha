#include "MyLibrary.h"
#include "MyColor.h"
#include "Input/InputManager.h"

// シーン
#include "Title/TitleScene.h"
#include "Record/SaveRecordScene.h"
#include "Record/LoadRecordScene.h"
#include "Event/Scene/LoadEventScene.h"
#include "Event/Scene/EventScene.h"


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
	Kokoha::registerAsset(U"Assets/");
	FontAsset::Register(U"10", 20, Typeface::Medium);
	FontAsset::Register(U"20", 20, Typeface::Medium);

	// シーンの設定
	MyApp sceneManager;
	sceneManager.add<Kokoha::TitleScene>     (SceneName::TITLE);
	sceneManager.add<Kokoha::SaveRecordScene>(SceneName::SAVE_RECORD);
	sceneManager.add<Kokoha::LoadRecordScene>(SceneName::LOAD_RECORD);
	sceneManager.add<Kokoha::LoadEventScene> (SceneName::LOAD_EVENT);
	sceneManager.add<Kokoha::EventScene>     (SceneName::EVENT);

	while (System::Update())
	{
		Kokoha::InputManager::instatnce().changeInputState();

		sceneManager.update();

		Kokoha::showFps();
	}
}
