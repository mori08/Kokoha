#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	AdventureScene�N���X
	������T������V�[��
	�K��LoadAdventureScene����J�ڂ���.
	*/
	class AdventureScene : public MyApp::Scene
	{
	public:

		AdventureScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}