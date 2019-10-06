#include "MyLibrary.h"
#include "Scene.h"
#include "MyColor.h"
#include "Input/InputManager.h"
#include "Title/TitleScene.h"


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
	FontAsset::Register(U"20", 20, Typeface::Medium);

	// シーンの設定
	MyApp sceneManager;
	sceneManager.add<Kokoha::TitleScene>(SceneName::TITLE);

	while (System::Update())
	{
		Kokoha::InputManager::instatnce().changeInputState();

		sceneManager.update();
	}
}
