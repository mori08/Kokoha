#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	EventScene�N���X
	�C�x���g�����s����V�[��
	�K��LoadEventScene����J�ڂ���.
	*/
	class EventScene : public MyApp::Scene
	{
	public:

		EventScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}