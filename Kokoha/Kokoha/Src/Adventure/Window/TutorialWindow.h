#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	TutorialWindowクラス
	AdventureSceneでの操作方法の説明
	*/
	class TutorialWindow : public AdventureWindow
	{
	public:

		TutorialWindow();

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}