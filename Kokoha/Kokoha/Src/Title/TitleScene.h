#pragma once


#include "../Scene.h"


namespace Kokoha
{
	/*
	TitleScene�N���X
	�^�C�g���V�[��
	ButtonManager���g���đ��̃V�[���ɑJ��
	*/
	class TitleScene : public MyApp::Scene
	{
	private:

	public:

		TitleScene(const InitData& init);

		void update() override;

		void draw() const override;
	};
}