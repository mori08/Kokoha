#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	TutorialWindowƒNƒ‰ƒX
	AdventureScene‚Å‚Ì‘€ì•û–@‚Ìà–¾
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