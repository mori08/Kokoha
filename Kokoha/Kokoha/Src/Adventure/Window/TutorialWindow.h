#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	TutorialWindow�N���X
	AdventureScene�ł̑�����@�̐���
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