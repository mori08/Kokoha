#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	GameScene�N���X
	�X�e�[�W���U������V�[��
	�K��LoadGameScene����J�ڂ���.
	*/
	class GameScene : public MyApp::Scene
	{
	public:

		GameScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}