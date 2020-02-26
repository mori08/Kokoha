#pragma once


#include "../Scene.h"


namespace Kokoha
{
	/*
	EndingScene�N���X
	���փQ�[�g�N���A���ɑJ�ڂ���V�[��
	*/
	class EndingScene : public MyApp::Scene
	{
	private:

		// �G���f�B���O�̖��O
		String mEndingName;

	public:

		EndingScene(const InitData& init);

	private:

		void update() override;

		void draw() const override;

	};
}